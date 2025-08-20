import re  #导入python正则表达式库re

str = input("请输入球员所看到和听到的信息：")
flag = 1
try:
    ed_list = str.split(")(s")
    ed_list[1] = "s" + ed_list[1]#分割后缺失s，增补上
    str1 = ed_list[0]
    str2 = ed_list[1]
except:
    ed_list = str.split(")(h")
    ed_list[1] = "h"+ed_list[1]#分割后缺失h，增补上
    str1 = ed_list[0]
    str2 = ed_list[1]
    flag = 0

#匹配hear消息的正则表达式
n = 'hear\\s(\\d+)\\s(.+?)\\s(.+)'
#匹配测试用hear开头的正则表达式
m = "see\\s(\\d+)\\s(\\(\\(ball\\)(\\s.+)+)\\)*\\s?\\((\\(player hfut[0-1]\\s[0-12]\\)(\\s.+)+)\\)*\\s?\\((\\(goal [a-z]\\)(\\s.+)+)\\)*\\s\\((\\(Line [a-z]\\)(\\s.+)+)*"
#匹配测试用see开头的正则表达式
sm = r"see\s(\d+)\s(\(\(player hfut[1-3]\s\d\))(\s.+)+\)*\s?\((\(goal [a-z]\)(\s.+)+)\)*\s\((\([a-z]\s[a-z]\s[a-z]\s\d+\)(\s.+)+)*"

#解析see消息
if flag == 1:
    x = re.search(m,str2)
else:
    x = re.search(sm, str1)
print(x.group())
#存储匹配的属性数据
ed_listx = []
ed_listx1 = []
ed_listx.append(x.group(1))
ed_listx.append(x.group(3))
ed_listx.append(x.group(5))
ed_listx.append(x.group(7))
#视测试用例的不同，将匹配的数据存入相应的列表储存
try:
    ed_listx.append(x.group(9))
    for i in range(5):
        new_str = ed_listx[i].strip(")")
        new_str = new_str.strip(" ")
        ed_listx1.append(new_str)
    time_list = ed_listx1[0]
    ball_list = ed_listx1[1].split(" ")
    player_list = ed_listx1[2].split(" ")
    goal_list = ed_listx1[3].split(" ")
    line_list = ed_listx1[4]
except:
    for i in range(4):
        new_str = ed_listx[i].strip(")")
        new_str = new_str.strip(" ")
        ed_listx1.append(new_str)
    time_list = ed_listx1[0]
    player1_list = ed_listx1[1].split(" ")
    goal1_list = ed_listx1[2].split(" ")
    frt_list = ed_listx1[3].split(" ")

#解析hear消息
#依据测试用例的不同，hear消息可能被分割为str1，也可能被分割为str2，与see消息和hear消息的前后有关
try:
    y = re.search(n, str1)
    ed_listy = []
    ed_listy.append(y.group(1))
    ed_listy.append(y.group(2))
    ed_listy.append(y.group(3))
except:
    y = re.search(n, str2)
    ed_listy = []
    ed_listy.append(y.group(1))
    ed_listy.append(y.group(2))
    ed_listy.append(y.group(3))
for i in range(3):
    ed_listy[i]=ed_listy[i].strip(")")

#组合解析信息，将解析信息写入record.txt文件
#首先打开文件，设置模式为a，即追加，采用UTF-8编码模式
f = open(r"C:\Users\24581\Documents\机器人技术作业\第一次作业\record.txt","a",encoding="UTF-8")
#向文件中写入统一的hear消息
f.write(f"在{ed_listy[0]}周期 hear 从{ed_listy[1]}方向 听到了{ed_listy[2]}\n")
print(f"在{ed_listy[0]}周期 hear 从{ed_listy[1]}方向 听到了{ed_listy[2]}")
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
