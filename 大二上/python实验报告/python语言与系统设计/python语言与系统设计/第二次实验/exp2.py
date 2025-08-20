
#实验一
#方法1
import random
#使用列表推导式生成1000个字符，然后把他们转换成字符串
data = str([str(random.randint(0,10)) for x in range(1000)])
num_frequency = []
for i in range(11):
    num_frequency.append(data.count(f"{i}"))
for i in range(11):
    print(f"字符{i}一共出现了{num_frequency[i]}次")
#方法2
import random
import string
# 生成包含1000个0-10字符的字符串
random_string = ''.join(random.choice(string.digits) for _ in range(1000))
# 使用字典统计每个字符出现的次数
char_count = {}
for char in random_string:
    if char in char_count:
        #如果该字符已经在字典内存在，那么该字符的键所对应的值加一
        char_count[char] += 1
    else:
        #如果该以该字符为名的键不存在与字典中，则创建这个键，并将其值赋为1
        char_count[char] = 1
# 打印结果
for char, count in char_count.items():
    print(f'字符{char}出现了 {count} 次')

#实验二

#方法一：使用系统类
flag = True
#首先由输入创建两个集合
print("请输入英文字母字符！(输入-1表示结束)")
set_A = []
set_B = []
while(True):
    str_read = str(input())
    if str_read == '-1':
        break
    set_A.append(str(str_read))
print("请输入英文字母字符！(输入-1表示结束)")
while(True):
    str_read = str(input())
    if str_read == '-1':
        break
    set_B.append(str(str_read))
set_A = set(set_A)
set_B = set(set_B)
#取两个集合的并集
set_union = set_A.union(set_B)
#取两个集合的差集
set_difference = set_A.difference(set_B).union(set_B.difference(set_A))
#取两个集合的交集
set_identical = set_A.difference(set_A.difference(set_B))
print(set_union)
print(set_difference)
print(set_identical)


#方法二：使用自定义类
class set_class:
    #自定义集合的并集方法
    def set_union(self,A:set,B:set)->set:
        storage = []
        A = tuple(A)
        B = tuple(B)
        for i in range(len(A)):
            storage.append(A[i])
            storage.append(B[i])
        storage = set(storage)
        return storage
    #定义集合的差集方法
    def set_difference(self,A:set,B:set)->set:
        storage = []
        A = tuple(A)
        B = tuple(B)
        for i in range(len(A)):
            if A[i] in B:
                pass
            else:
                storage.append(A[i])
        for i in range(len(B)):
            if B[i] in A:
                pass
            else:
                storage.append(B[i])
        storage = set(storage)
        return  storage
    #定义集合的交集方法
    def set_identical(self,A:set,B:set)->set:
        storage = []
        A = tuple(A)
        B = tuple(B)
        for i in range(len(A)):
            if A[i] in B:
                storage.append(A[i])
            else:
                pass
        storage = set(storage)
        return storage
flag = True
#首先由输入创建两个集合
print("请输入英文字母字符！(输入-1表示结束)")
set_A = []
set_B = []
while(True):
    str_read = str(input())
    if str_read == '-1':
        break
    set_A.append(str(str_read))
print("请输入英文字母字符！(输入-1表示结束)")
while(True):
    str_read = str(input())
    if str_read == '-1':
        break
    set_B.append(str(str_read))
set_A = set(set_A)
set_B = set(set_B)
#取两个集合的并集
set_union = set_class().set_union(set_A,set_B)
#取两个集合的差集
set_difference = set_class().set_difference(set_A,set_B)
#取两个集合的交集
set_identical = set_class().set_identical(set_A,set_B)
print(set_union)
print(set_difference)
print(set_identical)


#实验三
import random
import string
my_list = []
#首先生成十个元素的嵌套列表，其中列表中的每个元素为长度不超过十的字符串
for i in range(10):
    my_list.append([''.join(random.choice(string.digits+string.ascii_lowercase) for x in range(random.randint(1,10)))])
#输出生成的嵌套列表
print(my_list)
#将嵌套列表降维
for i in range(len(my_list)):
    my_list[i] = str(my_list[i])
    my_list[i] = my_list[i].strip("[]'")
#输出降维之后的列表
print(my_list)
#将降维后的列表的每个字符串的长度保存在一个列表中
str_length = []
for i in range(len(my_list)):
    str_length.append(len(my_list[i]))
print(str_length)
#依据长度列表来索引元素，每次输出一个字符串后，立即将长度列表该索引对应的元素置为0
for i in range(len(my_list)):
    list_index = str_length.index(max(str_length))
    str_length[list_index] = 0
    print(my_list[list_index])


#实验四
import random
list_int = []
for i in range(20):
    list_int.append(random.randint(1,10))
print(list_int)
#切片取出原列表中的所有元素
list_int_new1 = list_int[::]
#切片取出原列表中偶数位置的元素，步长设置为2
list_int_new2 = list_int[::2]
#切片取出原列表的逆序列表，步长取-1代表从后往前取
list_int_new3 = list_int[::-1]
#输出新的列表
print(list_int_new1)
print(list_int_new2)
print(list_int_new3)


#实验五
import  random
#data = str([str(random.randint(0,10)) for x in range(1000)])
#生成一个长度为20，元素为1-10整数的元组
data = [random.randint(1,10) for x in range(20)]
data = tuple(data)
#输出这个元组
print(data)
#过滤掉元组中的偶数，由于元组的不可修改特性，需要将其转换成列表再修改
data = list(data)
data1 = []
for i in range(len(data)):
    if data[i]%2 == 0:
        pass
    else:
        data1.append(data[i])
#输出过滤后的元组
print(tuple(data1))


#实验六
str1 = str(input("请输入一段英文:"))
#输出这个字符串
print(str1)
#先将这个字符串按照空格分割为一个个单词
my_list = str1.split(' ')
char_count = {}
#将这个字符串中的单词追加进字典
for char in my_list:
    if char in char_count:
        # 如果该字符已经在字典内存在，那么该字符的键所对应的值加一
        char_count[char] += 1
    else:
        # 如果该以该字符为名的键不存在与字典中，则创建这个键，并将其值赋为1
        char_count[char] = 1
#按照统一的格式输出
for i in range(len(my_list)):
    print(f"{my_list[i]}:{char_count[my_list[i]]}")


#实验七
import re
str1 = str(input("请输入一段英文:"))
my_list = str1.split(' ')
for i in range(len(my_list)):
    if len(my_list[i]) == 3:
        print(my_list[i])

