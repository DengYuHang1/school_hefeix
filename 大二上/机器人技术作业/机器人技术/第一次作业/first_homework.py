#物联网22-2班 2022216796 袁学宇

import re  #导入python正则表达式库re
import time #导入python时间库time

#测试用例1
str = "(hear 1022 -30 passto(23,24))(see 1022 ((ball) -20 20 1 -2) ((player hfut1 2) 45 23 0.5 1 22 40 ) ((goal r) 12 20) ((Line r) -30))"
#测试用例2
strone = "(see 2022 ((player hfut2 8) 40 23 1 6 21 33 ) ((goal r) 15 30) ((f r t 20) 5 24 ))(hear 2022 -10 “pass ball”)"
#视see消息和hear消息可能的前后关系不同，采取不同的形式将字符串分割为see和hear两部分
#此处使用测试用例1，若需使用测试用例2，将str替换为strone即可
try:
    my_list2 = str.split(")(s")
    my_list2[1] = "s" + my_list2[1]#分割后缺失s，增补上
    str1 = my_list2[0]
    str2 = my_list2[1]
except:
    my_list2 = str.split(")(h")
    my_list2[1] = "h"+my_list2[1]#分割后缺失h，增补上
    str1 = my_list2[0]
    str2 = my_list2[1]
print(str2)
#匹配hear消息的正则表达式
n = "hear\s(\d+)\s(.+?)\s(.+)"
#匹配测试用例1的正则表达式
m = "see\s(\d+)\s(\(\(ball\)(\s.+)+)\)*\s\((\(player hfut[0-1]\s[0-12]\)(\s.+)+)\)*\s\((\(goal [a-z]\)(\s.+)+)\)*\s\((\(Line [a-z]\)(\s.+)+)*"
#匹配测试用例2的正则表达式
m1 = "see\s(\d+)\s(\(\(player hfut[1-3]\s\d\))(\s.+)+\)*\s\((\(goal [a-z]\)(\s.+)+)\)*\s\((\([a-z]\s[a-z]\s[a-z]\s\d+\)(\s.+)+)*"

#解析see消息
#此处是使用测试用例1，若需使用测试用例2，则将m替换为m1，str2替换为str1即可
x = re.search(m,str2)
print(x.group())
#存储匹配的属性数据
my_listx = []
my_listx1 = []
my_listx.append(x.group(1))
my_listx.append(x.group(3))
my_listx.append(x.group(5))
my_listx.append(x.group(7))
#视测试用例的不同，将匹配的数据存入相应的列表储存
try:
    my_listx.append(x.group(9))
    for i in range(5):
        new_str = my_listx[i].strip(")")
        new_str = new_str.strip(" ")
        my_listx1.append(new_str)
    time_list = my_listx1[0]
    ball_list = my_listx1[1].split(" ")
    player_list = my_listx1[2].split(" ")
    goal_list = my_listx1[3].split(" ")
    line_list = my_listx1[4]
except:
    for i in range(4):
        new_str = my_listx[i].strip(")")
        new_str = new_str.strip(" ")
        my_listx1.append(new_str)
    time_list = my_listx1[0]
    player1_list = my_listx1[1].split(" ")
    goal1_list = my_listx1[2].split(" ")
    frt_list = my_listx1[3].split(" ")

#解析hear消息
#依据测试用例的不同，hear消息可能被分割为str1，也可能被分割为str2，与see消息和hear消息的前后有关
try:
    y = re.search(n, str1)
    my_listy = []
    my_listy.append(y.group(1))
    my_listy.append(y.group(2))
    my_listy.append(y.group(3))
except:
    y = re.search(n, str2)
    my_listy = []
    my_listy.append(y.group(1))
    my_listy.append(y.group(2))
    my_listy.append(y.group(3))
for i in range(3):
    my_listy[i]=my_listy[i].strip(")")

#组合解析信息，将解析信息写入record.txt文件
#首先打开文件，设置模式为a，即追加，采用UTF-8编码模式
f = open("E:/物联网专业课、课程设计资料/机器人技术/作业/record.txt","a",encoding="UTF-8")
#向文件中写入当前系统时间信息
f.write(f"{time.asctime()}\n")
#向文件中写入统一的hear消息
f.write(f"在{my_listy[0]}周期 hear 从{my_listy[1]}方向 听到了{my_listy[2]}\n")
#输出系统时间与解析到的hear消息
print(f"{time.asctime()}")
print(f"在{my_listy[0]}周期 hear 从{my_listy[1]}方向 听到了{my_listy[2]}")
#以下为分别写入和输出测试用例1或测试用例2的see消息
try:
    print(f"在{time_list}周期 see ball距离我的Direction是{ball_list[0]},Distance是"
        f"{ball_list[1]},DirChng是{ball_list[2]},Dischng是{ball_list[3]};"
        f"\nplayer hfut1 2距离我的Direction是{player_list[0]},Distance是{player_list[1]}"
        f",DirChng是{player_list[2]},DistChng是{player_list[3]},它的BodyDir是"
        f"{player_list[4]}和HeadDir是{player_list[5]};\ngoal r距离我的Direction是"
        f"{goal_list[0]},Distance是{goal_list[1]};\nLine r和我的角度是{line_list}度")
    f.write(f"在{time_list}周期 see ball距离我的Direction是{ball_list[0]},Distance是"
            f"{ball_list[1]},DirChng是{ball_list[2]},Dischng是{ball_list[3]};"
            f"\nplayer hfut1 2距离我的Direction是{player_list[0]},Distance是{player_list[1]}"
            f",DirChng是{player_list[2]},DistChng是{player_list[3]},它的BodyDir是"
            f"{player_list[4]}和HeadDir是{player_list[5]};\ngoal r距离我的Direction是"
            f"{goal_list[0]},Distance是{goal_list[1]};\nLine r和我的角度是{line_list}度\n")
except:
    print(f"在{time_list}周期 see palyer hfut2 8距离我的Direction是{player1_list[0]},Distance是{player1_list[1]}"
        f",DirChng是{player1_list[2]},DistChng是{player1_list[3]},它的BodyDir是"
        f"{player1_list[4]}和HeadDir是{player1_list[5]};\ngoal r距离我的Direction是"
        f"{goal1_list[0]},Distance是{goal1_list[1]};\nf r t20是5 24")
    f.write(f"在{time_list}周期 see palyer hfut2 8距离我的Direction是{player1_list[0]},Distance是{player1_list[1]}"
          f",DirChng是{player1_list[2]},DistChng是{player1_list[3]},它的BodyDir是"
          f"{player1_list[4]}和HeadDir是{player1_list[5]};\ngoal r距离我的Direction是"
          f"{goal1_list[0]},Distance是{goal1_list[1]};\nf r t20是5 24\n")
#最后将所有缓存中的内容写入硬盘
f.flush()







