
#实验一
import random
num = random.randint(1,10)
num = int(num)
num1 = int(input("请猜猜数字是几:"))
if num1 == num:
    print("恭喜你猜中正确答案")
elif num1 > num:
    print("数字猜大了哦")
    num2 = int(input("请再猜一次:"))
    if num2 == num:
        print("恭喜你猜中正确答案")
    elif num2 > num:
        print("数字猜大了哦")
        num3 = int(input("请再猜一次:"))
        if num3 == num:
            print("恭喜你终于猜中正确答案啦！")
        else:
            print(f"很可惜你还是没有猜对哦，正确答案是{num}啦。")
    else:
        print("数字猜小了哦")
        num4 = int(input("请再猜一次:"))
        if num4 == num:
            print("恭喜你终于猜中正确答案啦！")
        else:
            print(f"很可惜你还是没有猜对哦，正确答案是{num}啦。")
else:
    print("数字猜小了哦")
    num5 = int(input("请再猜一次:"))
    if num5 == num:
        print("恭喜你猜中正确答案")
    elif num5 > num:
        print("数字猜大了哦")
        num6 = int(input("请再猜一次:"))
        if num6 == num:
            print("恭喜你终于猜中正确答案啦！")
        else:
            print(f"很可惜你还是没有猜对哦，正确答案是{num}啦。")
    else:
        print("数字猜小了哦")
        num7 = int(input("请再猜一次:"))
        if num7 == num:
            print("恭喜你终于猜中正确答案啦！")
        else:
            print(f"很可惜你还是没有猜对哦，正确答案是{num}啦。")

#实验二


import random
num = random.randint(1,10)
i = 3
while(i):
    num1 = int(input("请猜猜数字是几:"))
    if num1 == num:
        print("恭喜你猜中正确答案")
        break
    elif num1 > num:
        print("数字猜大了哦")
    else:
        print("数字猜小了哦")
    i = i-1
if i==0:
 print(f"次数用完啦，正确答案是{num}")


#实验三(1)
def Fibonacci():
    n = int(input("请输入参数n"))
    p = 1
    q = 1
    print(1)
    print(1)
    while(1):
        p = p + q
        if p > n:
            break
        print(f"{p} ")
        q = q + p
        if q > n:
            break
        print(f"{q} ")
Fibonacci()


#实验三（2）
def find_primes(n):
    if n <= 2:
        return []
    primes = [2]
    for possiblePrime in range(3, n, 2):
        isPrime = True
        for num in range(2, int(possiblePrime ** 0.5) + 1):
            if possiblePrime % num == 0:
                isPrime = False
                break
        if isPrime:
            primes.append(possiblePrime)
    return primes
n = int(input("请输入一个大于2的自然数: "))
print(find_primes(n))


#实验三（3）
def judge_str():
    str_list = []
    str1 = str(input("请输入一个字符串"))
    for i in range(len(str1)):
        str_list.append(str1[len(str1)-i-1])
    str1 = list(str1)
    if str1 == str_list:
        print(True)
    else:
        print(False)
judge_str()


#实验三（4）
import random
def random_num():
    n = int(input("请输入参数n"))
    random_num_list = []
    result = []
    for i in range(n):
        random_num_list.append(random.randint(1,100))
    avarage = sum(random_num_list)/len(random_num_list)
    result.append(avarage)
    for i in range(n):
        if random_num_list[i]>avarage:
            result.append(random_num_list[i])
    result = tuple(result)
    print(random_num_list,result)
random_num()


#实验三（5）
def workday():
    print((((1+(2/100))**5)))
    for i in range(100):
        if(((((1+(i/100))**5)*0.99*0.99))**48>37.78):
            return(1+(i/100))
print(workday())


#实验四
lambda str1,str2:str1+str2
def str_connect(str_deal1):
    str1 = str(input("请输入字符串1"))
    str2 = str(input("请输入字符串2"))
    storage_list = []
    for i in range(len(str2)):
        if str2[i] in str1:
            print(str2[i])
            storage_list.append(str2[i])
    for i in range(len(storage_list)):
        str2 = str2.strip(storage_list[i])
    str3 = str_deal1(str1,str2)
    print(str3)
str_connect(lambda str1,str2:str1+str2)
