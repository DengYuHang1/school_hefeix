#实验一

class Student:
    def __init__(self, id, name, gender, age, scores):
        self.id = id
        self.name = name
        self.gender = gender
        self.age = age
        self.scores = scores

    def get_average_score(self):
        return sum(self.scores.values()) / len(self.scores)

def input_student_info():
    id = input('请输入学号: ')
    name = input('请输入姓名: ')
    gender = input('请输入性别: ')
    age = input('请输入年龄: ')
    scores = {}
    for i in range(1, 4):
        score = int(input(f'请输入第{i}门课程的成绩: '))
        scores[f'course_{i}'] = score
    return Student(id, name, gender, age, scores)

#将数据写入文件
def write_students_to_file(filename, students):
    with open(fileneam, 'a') as file:
        for student in students:
            line = f'{student.id},{student.name},{student.gender},{student.age},' + ','.join(str(score) for score in student.scores.values())
            file.write(line + '\n')

def rank_students(students):
    students.sort(key=lambda s: s.get_average_score())
    for i, student in enumerate(students):
        print(f'排名: {i+1}, 学号: {student.id}, 姓名: {student.name}, 性别: {student.gender}, 年龄: {student.age}, 三门课程成绩: {student.scores}, 平均值: {student.get_average_score()}')

students = [input_student_info() for _ in range(int(input('请输入学生数量: ')))]
write_students_to_file(r'C:\Users\24581\Documents\学校各科作业\python实验报告\python语言与系统设计\python语言与系统设计\第三次实验\class.txt', students)
rank_students(students)

#实验二
class Employee:
    def __init__(self, name, id, salary):
        self.name = name
        self.id = id
        self.salary = salary
    def pay(self):
        return self.salary
    def show(self):
        return f'姓名: {self.name}, 编号: {self.id}, 月薪: {self.salary}'

class Manager(Employee):
    def __init__(self, name, id, salary, bonus):
        super().__init__(name, id, salary)
        self.bonus = bonus
    def pay(self):
        return self.salary + self.bonus
    def show(self):
        return f'姓名: {self.name}, 编号: {self.id}, 月薪: {self.salary}, 奖金: {self.bonus}'

class Salesman(Employee):
    def __init__(self, name, id, salary, commission):
        super().__init__(name, id, salary)
        self.commission = commission
    def pay(self):
        return self.salary + self.commission
    def show(self):
        return f'姓名: {self.name}, 编号: {self.id}, 月薪: {self.salary}, 佣金: {self.commission}'

# 创建Manager和Salesman对象并调用它们的方法
manager = Manager('张三', '001', 10000, 2000)
salesman = Salesman('李四', '002', 8000, 1500)

print(manager.show())
print(f'实际月薪: {manager.pay()}')
print(salesman.show())
print(f'实际月薪: {salesman.pay()}')

#实验三

class Vehicle:
    def __init__(self, max_speed, weight):
        self.__max_speed = max_speed
        self.__weight = weight

class Bicycle(Vehicle):
    def __init__(self, max_speed, weight, height):
        super().__init__(max_speed, weight)
        self.__height = height
    @property
    def height(self):
        return self.__height
    @height.setter
    def height(self, value):
        if value > 0:
            self.__height = value
        else:
            raise ValueError("Height must be positive.")
    @height.deleter
    def height(self):
        del self.__height
    def set_max_speed(self, max_speed):
        self._Vehicle__max_speed = max_speed

# 创建Bicycle对象并设置MaxSpeed值
bicycle = Bicycle(20, 10, 1.5)
speed = int(input("请设置自行车的最大速度！"))
bicycle.set_max_speed(speed)
print(f'自行车的最大速度已设置为: {bicycle._Vehicle__max_speed} km/h')

#实验四

class MyQueue:
    def __init__(self, size):
        self.size = size
        self.data = []
        self.current = 0
    def is_empty(self):
        return self.current == 0
    def is_full(self):
        return self.current == self.size
    def get_front(self):
        if self.is_empty():
            return None
        return self.data[0]
    def enqueue(self, item):
        if not self.is_full():
            self.data.append(item)
            self.current += 1
    def dequeue(self):
        if not self.is_empty():
            item = self.data.pop(0)
            self.current -= 1
            return item

# 创建MyQueue对象并调用其方法
queue = MyQueue(5)
queue.enqueue('apple')
queue.enqueue('banana')
print(f'队头元素: {queue.get_front()}')
queue.dequeue()
print(f'队头元素: {queue.get_front()}')

#实验五
# 生成字符串列表
str_list = ['Hello', 'World', 'Python', 'Programming']
# 将字符串写入文件
with open('E:/物联网专业课、课程设计资料/python语言与系统设计/第三次实验/strings.txt','a',encoding="UTF-8") as f:
    for s in str_list:
        f.write(s + '\n')
# 读取文件并统计字符串的个数
with open('E:/物联网专业课、课程设计资料/python语言与系统设计/第三次实验/strings.txt', 'r',encoding="UTF-8") as f:
    lines = f.readlines()

print(f'字符串的个数: {len(lines)}')

#实验六
import re

def check_passwords(passwords):
    valid_passwords = []
    for password in passwords:
        if ((6 <= len(password) <= 12) and
            re.search("[a-z]", password) and
            re.search("[0-9]", password) and
            re.search("[A-Z]", password) and
            re.search("[$#@]", password)):
            valid_passwords.append(password)
    return valid_passwords
# 输入密码
passwords = input("请输入密码，用逗号分隔: ").split(',')
# 检查密码
valid_passwords = check_passwords(passwords)
print(len(valid_passwords))
# 输出有效的密码
print("有效的密码: ", ','.join(valid_passwords))
