'''
Author: Cerosop jmhsu920816@gmail.com
Date: 2023-05-16 23:14:30
LastEditors: Cerosop jmhsu920816@gmail.com
LastEditTime: 2023-05-16 23:48:12
FilePath: \c++\algorithm\hw3\gen.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
from random import randint as ri
f = open('C:/Users/hsu/Desktop/c++/algorithm/hw3/in.txt', 'w')
f.write(str(ri(100,101)) + ' ')
a = ri(10000000,10000001)
f.writelines(str(a) + '\n')

for _ in range(0,a):
    f.write(str(ri(1,10000)) + ' ')