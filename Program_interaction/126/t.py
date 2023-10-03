f1=open("./t1","rb")#利用t1通道进行输入数据
f2=open("./t2","wb")#t2通道输出数据
sum=0
for i in range(3000):
    s=f1.readline()
    if sum >=500:
        print(s)
        print(f1.read())
        break
    index=s.find(b": ")#如果有这个标志说明这一行是需要运算的
    if index != -1:
        sum+=1
        t1=s[index+2:-1]
        #print(t1)
        t2=eval(t1)#运算得到结果
        print("%d : %d"%(sum,t2))
        f2.write(b"%d\n"%t2)#写入t2传回结果
        f2.flush()#缓冲区清空是个大坑啊，我又栽这了好久。。。不加这一行原程序得不到我们的运行结果

f1.close()
f2.close()
