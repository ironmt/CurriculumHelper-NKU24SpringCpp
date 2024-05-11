import socket
import openai

# 初始化 OpenAI 客户端
openai.api_key = 'your-openai-api-key'

def chat_with_gpt(text):
    """ 使用 ChatGPT 生成回复 """
    response = openai.Completion.create(
        engine="text-davinci-002",  # 根据需要选择合适的模型
        prompt=text,
        max_tokens=150
    )
    return response.choices[0].text.strip()

def main():
    host = '127.0.0.1'
    port = 23333

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((host, port))
        s.listen()
        print(f"Server listening on {host}:{port}")

        while True:
            conn, addr = s.accept()
            with conn:
                print(f"Connected by {addr}")
                data = conn.recv(1024).decode('utf-8')
                if not data:
                    break
                print(f"Received: {data}")

                # 调用 GPT-3
                response = chat_with_gpt(data)
                print(f"Sending: {response}")
                conn.sendall(response.encode('utf-8'))

if __name__ == "__main__":
    main()
