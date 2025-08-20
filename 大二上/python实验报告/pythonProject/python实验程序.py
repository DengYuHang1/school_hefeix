 
# #实验一.1
import random
num = random.randint(1,200)
MY_num = eval(input('请输入整数：'))
if MY_num > num:
    print("too large")
    print(f"游戏结束，正确答案为{num}")
elif MY_num < num:
    print("too small")
    print(f"游戏结束，正确答案为{num}")
else:
    print("恭喜你猜对了！")


# #实验一.2
# import random
# num = random.randint(1,200)
# flag = 1
# times = 5
# while times and flag==1:
#     MY_num = eval(input('请输入整数：'))
#     if MY_num > num:
#         print("too large")
#     elif MY_num < num:
#         print("too small")
#     else:
#         print("恭喜你猜对了！")
#         flag = 0
#     times-=1
# if flag:
#     print(f"游戏结束，正确答案为{num}")


#
#
# #实验一.3.(1)
# def Fibonacci (n):
#     if n>0:
#         print(0)
#         if n>1:
#             f1 = 0
#             f2 = 1
#             while f2 <n:
#                 print(f2,end=',')
#                 temp = f1
#                 f1 = f2
#                 f2 = f2 + temp
#
# Fibonacci(10)
#
#
#
# #实验一.3.(2)
# num = eval(input('输入大于2的整数：'))
# list_num = []
# for i in range(2,num):
#     flag = 1
#     for j in range(2,int(i/2)+1):
#         if i%j == 0:
#             flag = 0
#             break
#     if flag:
#         list_num.append(i)
#
# print(list_num)
#
#
#
#实验一.3.(3)
# str1 = input('输入字符串：')
# str2 = ''.join(reversed(str1))
# if str1 == str2:
#     print(True)
# else:
#     print(False)
#
#
#
#实验一.3.(4)
# import random
#
# def function(n):
#     numlist = []    #包含n个整数的列表
#     numtuple = []   #输出列表
#     sum = 0
#     for i in range(n):
#         a = random.randint(0,200)
#         sum += a
#         numlist.append(a)
#
#     numtuple.append(sum/n)
#     print(numlist)
#
#     for i in range(n):
#         if numlist[i]>numtuple[0]:
#             numtuple.append(numlist[i])
#     return tuple(numtuple)
#
# print(function(4))  #测试打印函数

#
#
#实验一.3.(5)
# def workforce():
#     for i in range(1,100):
#         if(((1+i/100)**5*0.99*0.99)**52*(1+i/100))>37.78:
#             print(f'工作日要努力{i}%')
#             return
# workforce()
# #
#
#实验一.4
# def find(a, b):
#     str1=''
#     for i in b:
#         if i not in a:
#             str1 += i
#     return str1
#
# str1 = input('1:')
# str2 = input('2:')
# str3 = lambda str1,str2:str1+find(str1,str2)
# print(str3(str1,str2))
#
#
# #实验二(1)
# #方法1
# import random
# #使用列表推导式生成1000个字符，然后把他们转换成字符串
# data = str([str(random.randint(0,10)) for x in range(1000)])
# num_frequency = []
# for i in range(11):
#     num_frequency.append(data.count(f"{i}"))
# for i in range(11):
#     print(f"字符{i}一共出现了{num_frequency[i]}次")
# #方法2
# import random
# import string
# # 生成包含1000个0-10字符的字符串
# random_string = ''.join(random.choice(string.digits) for _ in range(1000))
# # 使用字典统计每个字符出现的次数
# char_count = {}
# for char in random_string:
#     if char in char_count:
#         #如果该字符已经在字典内存在，那么该字符的键所对应的值加一
#         char_count[char] += 1
#     else:
#         #如果该以该字符为名的键不存在与字典中，则创建这个键，并将其值赋为1
#         char_count[char] = 1
# # 打印结果
# for char, count in char_count.items():
#     print(f'字符{char}出现了 {count} 次')
#
#
# #实验二（2）
#系统类
# setA={1,2,3,4}
# setB={5,7,3}
# setC=setA-setB
# print("集合的差集为："+str(setC))
# print("交集为："+str(setA.intersection(setB)))
# print("并集为："+str(setA.union(setB)))
#
# #自定义类
# class set_class:
#     #自定义集合的并集方法
#     def set_union(self,A:set,B:set)->set:
#         storage = []
#         A = tuple(A)    #将集合转化为元组，集合无序，元组有序
#         B = tuple(B)
#         for i in range(len(A)):
#             storage.append(A[i])
#         for i in range(len(B)):
#             storage.append(B[i])
#         storage = set(storage)
#         return storage
#     #定义集合的差集方法
#     def set_difference(self,A:set,B:set)->set:
#         storage = []
#         A = tuple(A)
#         B = tuple(B)
#         for i in range(len(A)):
#             if A[i] in B:
#                 pass
#             else:
#                 storage.append(A[i])
#         for i in range(len(B)):
#             if B[i] in A:
#                 pass
#             else:
#                 storage.append(B[i])
#         storage = set(storage)
#         return  storage
#     #定义集合的交集方法
#     def set_identical(self,A:set,B:set)->set:
#         storage = []
#         A = tuple(A)
#         B = tuple(B)
#         for i in range(len(A)):
#             if A[i] in B:
#                 storage.append(A[i])
#             else:
#                 pass
#         storage = set(storage)
#         return storage
# flag = True
# #首先由输入创建两个集合
# print("请输入英文字母字符！(输入-1表示结束)")
# set_A = []
# set_B = []
# while(True):
#     str_read = str(input())
#     if str_read == '-1':
#         break
#     set_A.append(str(str_read))
# print("请输入英文字母字符！(输入-1表示结束)")
# while(True):
#     str_read = str(input())
#     if str_read == '-1':
#         break
#     set_B.append(str(str_read))
# set_A = set(set_A)
# set_B = set(set_B)
# #取两个集合的并集
# set_union = set_class().set_union(set_A,set_B)
# #取两个集合的差集
# set_difference = set_class().set_difference(set_A,set_B)
# #取两个集合的交集
# set_identical = set_class().set_identical(set_A,set_B)
# print(set_union)
# print(set_difference)
# print(set_identical)
#
#
#
# #实验三
# import random
# import string
# my_list = []
# #首先生成十个元素的嵌套列表，其中列表中的每个元素为长度不超过十的字符串
# for i in range(10):
#     my_list.append([''.join(random.choice(string.digits+string.ascii_lowercase) for x in range(random.randint(1,10)))])
# #输出生成的嵌套列表
# print(my_list)
# #将嵌套列表降维
# for i in range(len(my_list)):
#     my_list[i] = str(my_list[i])
#     my_list[i] = my_list[i].strip("[]'")
# #输出降维之后的列表
# print(my_list)
# #利用sorted函数对列表元素长度进行降序排序
# str_length =sorted(my_list,key=lambda item:len(item),reverse=True)
# print(str_length)
# #
#
# #实验四
# import random
# list_int = []
# for i in range(20):
#     list_int.append(random.randint(1,10))
# print(list_int)
# #切片取出原列表中的所有元素
# list_int_new1 = list_int[::]
# #切片取出原列表中偶数位置的元素，步长设置为2
# list_int_new2 = list_int[::2]
# #切片取出原列表的逆序列表，步长取-1代表从后往前取
# list_int_new3 = list_int[::-1]
# #输出新的列表
# print(list_int_new1)
# print(list_int_new2)
# print(list_int_new3)

#
# #实验五
# import  random
# #data = str([str(random.randint(0,10)) for x in range(1000)])
# #生成一个长度为20，元素为1-10整数的元组
# data = [random.randint(1,10) for x in range(20)]
# data = tuple(data)
# #输出这个元组
# print(data)
# #过滤掉元组中的偶数，由于元组的不可修改特性，需要将其转换成列表再修改
# data = list(data)
# data1 = []
# for i in range(len(data)):
#     if data[i]%2 == 0:
#         pass
#     else:
#         data1.append(data[i])
# #输出过滤后的元组
# print(tuple(data1))

#
# #实验六
# str1 = str(input("请输入一段英文:"))
# #输出这个字符串
# print(str1)
# #先将这个字符串按照空格分割为一个个单词
# my_list = str1.split(' ')
# #利用字典推导式
# a = {key: my_list.count(key) for key in set(my_list)}
# print(a)
#
#
#
# #实验七
# import re
# str1 = str(input("请输入一段英文:"))
# pattern=r'\b[a-zA-Z]{3}\b'
# print(re.findall(pattern,str1))

#
# #第三组实验(1)
# class Student:
#     def __init__(self, id, name, gender, age, scores):
#         self.id = id
#         self.name = name
#         self.gender = gender
#         self.age = age
#         self.scores = scores
#
#     def get_average_score(self):
#         return sum(self.scores.values()) / len(self.scores)
#
# def input_student_info():
#     id = input('请输入学号: ')
#     name = input('请输入姓名: ')
#     gender = input('请输入性别: ')
#     age = input('请输入年龄: ')
#     scores = {}
#     for i in range(1, 4):
#         score = int(input(f'请输入第{i}门课程的成绩: '))
#         scores[f'course_{i}'] = score
#     return Student(id, name, gender, age, scores)
#
# #将数据写入文件
# def write_students_to_file(filename, students):
#     with open(filename, 'a') as file:
#         for student in students:
#             line = f'{student.id},{student.name},{student.gender},{student.age},' + ','.join(str(score) for score in student.scores.values())
#             file.write(line + '\n')
#
# #根据平均分打印学生排名
# def rank_students(students):
#     students.sort(key=lambda s: s.get_average_score())
#     for i, student in enumerate(students):
#         print(f'排名: {i+1}, 学号: {student.id}, 姓名: {student.name}, 性别: {student.gender}, 年龄: {student.age}, 三门课程成绩: {student.scores}, 平均值: {student.get_average_score()}')
#
# students = [input_student_info() for _ in range(int(input('请输入学生数量: ')))]
# write_students_to_file(r'C:\Users\24581\Documents\学校各科作业\python实验报告\python语言与系统设计\python语言与系统设计\第三次实验\class.txt', students)
# rank_students(students)

#
# #(2)
# class Employee:
#     def __init__(self, name, id, salary):
#         self.name = name
#         self.id = id
#         self.salary = salary
#     def pay(self):
#         return self.salary
#     def show(self):
#         return f'姓名: {self.name}, 编号: {self.id}, 月薪: {self.salary}'
#
# class Manager(Employee):
#     def __init__(self, name, id, salary, bonus):
#         super().__init__(name, id, salary)
#         self.bonus = bonus
#     def pay(self):
#         return self.salary + self.bonus
#     def show(self):
#         return f'姓名: {self.name}, 编号: {self.id}, 月薪: {self.salary}, 奖金: {self.bonus}'
#
# class Salesman(Employee):
#     def __init__(self, name, id, salary, commission):
#         super().__init__(name, id, salary)
#         self.commission = commission
#     def pay(self):
#         return self.salary + self.commission
#     def show(self):
#         return f'姓名: {self.name}, 编号: {self.id}, 月薪: {self.salary}, 佣金: {self.commission}'
#
# # 创建Manager和Salesman对象并调用它们的方法
# manager = Manager('张三', '001', 10000, 2000)
# salesman = Salesman('李四', '002', 8000, 1500)
#
# print(manager.show())
# print(f'实际月薪: {manager.pay()}')
# print(salesman.show())
# print(f'实际月薪: {salesman.pay()}')

#
# #实验三
#
# class Vehicle:
#     def __init__(self, max_speed, weight):
#         self.__max_speed = max_speed
#         self.__weight = weight
#
# class Bicycle(Vehicle):
#     def __init__(self, max_speed, weight, height):
#         super().__init__(max_speed, weight)
#         self.__height = height
#     @property
#     def height(self):
#         return self.__height
#     @height.setter
#     def height(self, value):
#         if value > 0:
#             self.__height = value
#         else:
#             raise ValueError("Height must be positive.")
#     @height.deleter
#     def height(self):
#         del self.__height
#     def set_max_speed(self, max_speed):
#         self._Vehicle__max_speed = max_speed
#
# # 创建Bicycle对象并设置MaxSpeed值
# bicycle = Bicycle(20, 10, 1.5)
# speed = int(input("请设置自行车的最大速度！"))
# bicycle.set_max_speed(speed)
# print(f'自行车的最大速度已设置为: {bicycle._Vehicle__max_speed} km/h')

# #实验四
#
# class MyQueue:
#     def __init__(self, size):
#         self.size = size#最大容量
#         self.data = []
#         self.current = 0
#     def is_empty(self):
#         return self.current == 0
#     def is_full(self):
#         return self.current == self.size
#     def get_front(self):
#         if self.is_empty():
#             return None
#         return self.data[0]
#     def enqueue(self, item):
#         if not self.is_full():
#             self.data.append(item)
#             self.current += 1
#     def dequeue(self):
#         if not self.is_empty():
#             item = self.data.pop(0)
#             self.current -= 1
#             return item
#
# # 创建MyQueue对象并调用其方法
# queue = MyQueue(5)
# queue.enqueue('apple')
# queue.enqueue('banana')
# print(f'队头元素: {queue.get_front()}')
# queue.dequeue()
# print(f'队头元素: {queue.get_front()}')

# #实验五
# 生成字符串列表
# str_list = ['Hello', 'World', 'Python', 'Programming']
# # 将字符串写入文件
# with open(r'C:\Users\24581\Documents\学校各科作业\python实验报告\python语言与系统设计\python语言与系统设计\第三次实验\class.txt','a',encoding="UTF-8") as f:
#     for s in str_list:
#         f.write(s + '\n')
# # 读取文件并统计字符串的个数
# with open(r'C:\Users\24581\Documents\学校各科作业\python实验报告\python语言与系统设计\python语言与系统设计\第三次实验\class.txt', 'r',encoding="GBK") as f:
#     lines = f.readlines()
#
# print(f'字符串的个数: {len(lines)}')
#
#
# #实验六
# import re
# def check_passwords(passwords):
#     valid_passwords = []
#     for password in passwords:
#         if ((6 <= len(password) <= 12) and
#             re.search("[a-z]", password) and
#             re.search("[0-9]", password) and
#             re.search("[A-Z]", password) and
#             re.search("[$#@]", password)):
#             valid_passwords.append(password)
#     return valid_passwords
# # 输入密码
# passwords = input("请输入密码，用逗号分隔: ").split(',')
# # 检查密码
# valid_passwords = check_passwords(passwords)
# print(len(valid_passwords))
# # 输出有效的密码
# print("有效的密码: ", ','.join(valid_passwords))
