import socket

import json
import requests
import sys
from requests.auth import HTTPBasicAuth
import time
from zhipuai import ZhipuAI

RETRIES = 25
MAX_TOKENS = 1024 #最长生成长度
BETA_URL = "http://43.163.219.59:8001/beta"
MODEL = "gpt-3.5-turbo-1106"
#backoff.on_exception(backoff.expo, (TypeError, KeyError, JSONDecodeError, ReadTimeout, ConnectionError, ConnectTimeout), max_tries=RETRIES)

def generate_answer(contexts, model=MODEL, temperature=0):
    """
    context: str
    """
    print("question context: ")
    print(contexts)
    data = {
        "model": model,
        "messages": contexts, # 格式需要为[..., {'role': 'user', 'content': '询问内容'}] 
        "max_tokens": MAX_TOKENS,
        "temperature": temperature,
        #"top_p": 1,
        #"frequency_penalty": 0.0,
        #"presence_penalty": 0.0,
        #"stop": stop
    }
    data = json.dumps(data)
    completion = requests.post(url=BETA_URL, data=data, auth=HTTPBasicAuth(username="",password=""), timeout=300).text
    # print(completion)
    completion = json.loads(completion)
    # print(completion)
    # print()
    if 'usage' not in completion:
        raise KeyError('usage')
#    return completion["choices"][0]["message"]["content"], completion["usage"]["prompt_tokens"], completion["usage"]["completion_tokens"] #返回的依次是回复内容、输入的token数量，生成的的token数量
    return completion["choices"][0]["message"]["content"]

# print(generate_answer([{'role': 'user', 'content': '你是copilot，模仿copilot补全我的笔记，你的回答内容应当可以直接连接在我的问题后面，语言逻辑很自然。不用重复我的问题，给出专家级回答。我的笔记内容：供需曲线的定义是'}]))

def gene_zhipu_response(contexts):
    client = ZhipuAI(api_key="79e87f391b89381f49e9d0d8f8dd380d.TKNWeKdp4G3R7yzz") # 请填写您自己的APIKey
    response = client.chat.completions.create(
        model="glm-4",  # 填写需要调用的模型名称
        messages=[
            {"role": "user", "content": "你是copilot，模仿copilot补全我的笔记。不用重复我的问题，不要给出多余的询问和请求和指导，只是写一份完美的笔记。给出专家级回答，我是一名大一学生。你的回答内容应当直接连接在我的问题后面，语言逻辑自然。我的笔记内容："},
            {"role": "user", "content": contexts},
        ],
    )
    print(response.choices[0].message)
    return response.choices[0].message.content


target_host = "127.0.0.1" #服务器端地址
target_port = 9000  #端口号

init_str = "你是copilot，模仿copilot补全我的笔记，不用重复我的问题，给出专家级回答。你的回答内容应当直接连接在我的问题后面，语言逻辑自然。我的笔记内容："

while True:

    client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client.connect((target_host,target_port)) 

    data = client.recv(1024)

    if not data:
        break
    data = data.decode('utf-8')
    print("data:", data)

    flag = False;

    while flag == False:
        try:
            # ans = generate_answer(init_str + data);
            ans = gene_zhipu_response(data);
            flag = True;
        except Exception as e:
            time.sleep(10)
            print("error:" + str(e));
            continue;

    print("ans:" + ans);
    client.send(ans.encode());

client.close()
