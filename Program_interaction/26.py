import subprocess

input_directory = '/tmp/ljokqy'
output_file = '/challenge/embryoio_level26'

# 读取输入目录中的内容
with open(input_directory, 'r') as input_file:
    input_data = input_file.read()
    # 使用subprocess模块执行命令并将输入数据传递给目标程序
    subprocess.run(['/challenge/embryoio_level26'],stdin=open('/tmp/ljokqy'))
