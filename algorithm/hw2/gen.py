'''
Author: Cerosop jmhsu920816@gmail.com
Date: 2023-05-05 15:14:28
LastEditors: Cerosop jmhsu920816@gmail.com
LastEditTime: 2023-05-07 00:31:36
FilePath: \c++\algorithm\hw2\gen.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import random
file = open("algorithm\hw2\in10000.txt", "+w")
k = 100
for h in range(2000,2001):
    # print("1000 1000", k)
    
    for q in range(1, 101):
        file.writelines(str(h) + ' ' + str(h) + ' ' + str(k) + "\n")
        for _ in range(0,k):
            # a = random.randint(1,100)
            # print(a)
            file.write(str(q) + ' ')
            for i in range(0,q):
                up = random.randint(0,2)
                x = random.randint(2,h - 1)
                y = random.randint(2,h - 1)
                # print(x,y)
                file.write(str(x)+ " " + str(y) + " ")
                if up == 0:
                    x += 1
                else:  
                    y += 1
                # print(x,y)
                file.write(str(x) + " " +str(y) + " ")
            file.write("\n")