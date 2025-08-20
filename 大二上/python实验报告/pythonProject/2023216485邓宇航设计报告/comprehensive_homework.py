import tkinter as tk
from tkinter import ttk  # ttk中有更多控件
from tkinter import messagebox
import re

gWin = None  # 表示窗口
gDishes = (("清汤(20元)", "滋补(40元)", "鸳鸯(60元)"),  # 锅底
           ("香菜(10元)", "麻酱(20元)", "韭花(20元)"),  # 佐料
           ("羊肉(30元)", "肥牛(40元)", "白菜(10元)", "茼蒿(20元)", "毛肚(30元)"))  # 菜品

read_user = []
num1 = 0
user = [("yuanxueyu1", "123456", "普通用户", 1000),
        ("yuanxueyu2", "123456", "会员", 2000),
        ("yuanxueyu3", "123456", "vip", 3000)]


def addToListbox(listbox, lst):
    for x in lst:
        listbox.insert(tk.END, x)  # 将x添加到列表框尾部


# 选择对应的折扣以及计算总的折扣价格
def doDiscount():
    gWin.discount = [1, 0.9, 0.8][gWin.custom.get()]
    gWin.lbHint["text"] = "饭菜总价：" + str(int(gWin.totalCost * gWin.discount)) \
                          + "元"
    gWin.lbHint["fg"] = "black"


# gWin.cbxCategory选项变化时被调用，即下拉菜单的内容
def categoryChanged(event):
    gWin.lsbDishes.delete(0, tk.END)  # 首先将原有的内容删除，删除全部内容,delete(x,y)删除第x项到第y项
    idx = gWin.cbxCategory.current()  # gWin.cbxCategory当前选中的是第idx项，即下拉菜单中的第几项
    addToListbox(gWin.lsbDishes, gDishes[idx])  # 根据下拉菜单中的选择，装入相应菜单
    gWin.lsbDishes.select_set(0, 0)


# 添加按钮对应的事件响应函数
def btAdd_click():
    # btAdd["state"] = tk.DISABLED  tk.NORMAL
    # 得到当前用户选择的菜品，调用lsbdishes.curselection来获取
    sel = gWin.lsbDishes.curselection()  # sel形如 (1,2,3)
    # 若所获得的元素是一个空元组，代表什么都没有选中
    if sel == ():
        gWin.lbHint["text"] = "您还没有选中要添加的菜"
        gWin.lbHint["fg"] = "red"
    else:
        # 获取所选中的菜品
        dish = gWin.lsbDishes.get(sel)
        # 获取所选菜品的价格和数量
        price, num = int(dish[3:5]), gWin.dishNum.get()
        # 将所有内容添加到我的餐桌，包括当前下拉框的内容category、菜品名称和数量
        gWin.lsbTable.insert(tk.END, "[" + gWin.category.get() + "]" + dish + " X" + num)
        # 计算当前所选菜品的总价
        gWin.totalCost += price * int(num)
        gWin.lbHint["text"] = "饭菜总价：" + str(int(gWin.totalCost * gWin.discount)) + "元"
        gWin.lbHint["fg"] = "black"


# 以下为从我的餐桌中删除选中的菜品
def btDelete_click():
    # 与添加菜品一样，首先获取我的餐桌中选中的菜品，结果以一个元组的形式返回
    sel = gWin.lsbTable.curselection()
    if sel == ():
        gWin.lbHint["text"] = "您还没有选中要删除的菜"
        gWin.lbHint["fg"] = "red"
    else:
        # 获取所选菜品的信息
        for i in sel:
            # 获取菜品名称
            dish = gWin.lsbTable.get(i)
            # 获取菜品单价
            price = int(dish[7:9])
            # 获取菜品的总价（如果有多份的话）
            price *= int(dish[dish.index("X") + 1:])
            # 修改当前总价
            gWin.totalCost -= price
        gWin.lbHint["text"] = "饭菜总价：" + str(int(gWin.totalCost * gWin.discount)) + "元"
        gWin.lbHint["fg"] = "black"
        # 修改当前我的餐桌的菜品
        for i in sel[::-1]:
            gWin.lsbTable.delete(i)


# 结算按钮的时间响应函数
def purchase():
    # 获取当前label的内容
    show = str(gWin.lbmoney.cget("text"))
    # 使用正则表达式去匹配内容里的余额
    pattern = "账户余额：(\d*)元"
    moneycount = re.search(pattern, show)
    num = int(moneycount.group(1))
    # 分两种情况处理，如果余额足够则消费对应的金额
    if ((num > int(gWin.totalCost * gWin.discount)) and (int(gWin.totalCost * gWin.discount) != 0)):
        gWin.lbmoney["text"] = "账户余额：" + str(int(num - gWin.totalCost * gWin.discount)) + "元"
        messagebox.showinfo(title="结算完成！", message="一共消费：" + str(int(gWin.totalCost * gWin.discount)) + "元")
        # 将消费后的账户余额记录在相应的文件中，以免关闭窗口后余额丢失
        f = open(f"E:/计算机专业课、课程设计资料/python语言与系统设计/大作业/{user[num1][0]}.txt", "a", encoding="UTF-8")
        f.write(f"{user[num1][0]} 账户余额：" + str(int(num - gWin.totalCost * gWin.discount)) + "\n")
    # 若没有选中任何餐品，则弹出警告框，提示用户还未点餐
    elif ((num > int(gWin.totalCost * gWin.discount)) and (int(gWin.totalCost * gWin.discount) == 0)):
        messagebox.showwarning(title="您未点餐！", message="您还未点餐！")
    # 如果余额不足则弹出错误框，警告余额不足
    else:
        messagebox.showerror(title="余额不足！", message="账户余额：" + str(num) + " \n余额不足，无法完成支付！")


# 以下为登录按钮的时间响应函数
def signin():
    # 创建一个对话窗口gDialog
    global gDialog
    # 控制始终聚焦在刚创建的对话窗口中
    gDialog = tk.Toplevel(gWin)
    gDialog.grab_set()
    gDialog.title("请输入用户名和密码")
    # 设置登录窗口不可调整大小
    gDialog.resizable(False, False)
    # 创建两个标签，分别为用户名和密码
    label1 = tk.Label(gDialog, text="用户名：")
    label2 = tk.Label(gDialog, text="密码：")
    # 创建两个输入框
    gDialog.etUsername = tk.Entry(gDialog)
    gDialog.etPassword = tk.Entry(gDialog)
    # 放置两个标签和对话框
    label1.grid(row=0, column=0, padx=5, pady=5)
    label2.grid(row=1, column=0, padx=5, pady=5)
    gDialog.etUsername.grid(row=0, column=1, padx=5, pady=5)
    gDialog.etPassword.grid(row=1, column=1, padx=5, pady=5)
    # 创建两个按钮，分别为确定和取消，并分别指定响应函数及其放置位置
    btOk = tk.Button(gDialog, text="确定", command=check_user)
    btOk.grid(row=2, column=0, padx=5, pady=5)
    btCancel = tk.Button(gDialog, text="取消", command=gDialog.destroy)
    btCancel.grid(row=2, column=1, padx=5, pady=5)


# 点击确定之后，确定按钮的时间响应函数
def check_user():
    # 分别获取用户名和密码输入框中的内容
    username = gDialog.etUsername.get()
    password = gDialog.etPassword.get()
    # 设置判断变量judge，用于判断用户名是否正确
    judge = 0
    # 将获取的用户名在存储用户信息的列表中进行顺序查找，如果找到，则保存其下标，同时将judge置1
    for i in range(len(user)):
        if (user[i][0] == str(username)):
            global num1
            num1 = i
            judge = 1
            break
    # 查找结束后judge为0，表示未找到，则弹出一个对话窗口，报错未找到用户
    if (judge == 0):
        messagebox.showerror(title="错误", message="用户名错误！未找到该用户！")
    # 如果不为0，即用户名正确，则继续判断密码是否正确
    else:
        # 依据保存的下标判断存储的密码与输入的是否相等
        # 如果不相等，则弹出对话窗口，报错密码错误
        if (user[num1][1] != str(password)):
            messagebox.showerror(title="错误", message="密码错误！请重新输入！")
        # 如果相等，则弹出对话窗口，提示登录成功，同时关闭登录窗口，执行成功登录函数successfullylogin函数
        else:
            messagebox.showinfo(title="登录成功！",
                                message="欢迎你：" + str(username) + f"\n你的用户等级是：{user[num1][2]}")
            gDialog.destroy()
            successfullylogin(num1)


# 成功登录函数
def successfullylogin(i):
    # 首先将用户的账户余额更改为对应的余额
    # 如果用户不是第一次进入火锅店消费，则读取相应的记录文件，获取当前余额
    # 需要注意，运行程序时需要确定文件的路径是否正确
    try:
        f = open(f"E:/计算机专业课、课程设计资料/python语言与系统设计/大作业/{user[num1][0]}.txt", "r", encoding="UTF-8")
        # 依次读取文件中的每一行，将其放置在一个列表read_user中
        for line in f:
            read_user.append(line)
        # 使用正则表达式去匹配余额，匹配对象是最新的消费记录，也就是列表的最后一个元素
        string1 = read_user[len(read_user) - 1]
        # 匹配余额的模式字符串
        pattern = "yuanxueyu[0-9] 账户余额：(\d+)"
        readmoney = re.search(pattern, string1)
        money_num = readmoney.group(1)
        # 修改当前账户余额
        gWin.lbmoney["text"] = "账户余额：" + str(money_num) + "元"
    # 如果是第一次进入火锅店消费，则账户余额为默认值
    except:
        gWin.lbmoney["text"] = "账户余额：" + str(user[i][3]) + "元"
    # 然后将界面的欢迎信息更改为对应的用户名
    gWin.lbuser["text"] = "尊敬的：" + str(user[i][0]) + f" ({user[i][2]})"
    # 最后判断用户的级别，解除其对应折扣权限的限制
    if (user[i][2] == "会员"):
        gWin.rb2.config(state="normal")
        gWin.rb3.config(state="disabled")
    elif (user[i][2] == "vip"):
        gWin.rb2.config(state="disabled")
        gWin.rb3.config(state="normal")
    else:
        pass


# 由于执行操作太多，故统一写在主函数中，最后调用主函数即可
def main():
    global gWin
    gWin = tk.Tk()
    gWin.title("Python火锅店")
    gWin.geometry("520x300")
    gWin.totalCost, gWin.discount = 0, 1  # 总价和折扣
    # gWin.resizable(False,False) #gWin不可改变大小
    lb = tk.Label(gWin, text="欢迎光临Python火锅店", fg="black", font=('黑体', 20, 'bold'))
    lb.grid(row=0, column=0, columnspan=2, sticky="EW")
    # 以下为欢迎用户的标签
    gWin.lbuser = tk.Label(gWin, text="尊敬的：未登录", fg="black", font=('宋体', 10))
    gWin.lbuser.grid(row=0, column=2, columnspan=2, sticky='WS')
    # 以下为生成选择“菜品、锅底、佐料”的下拉列表框
    gWin.category = tk.StringVar()  # 对应组合框gWin.cbxCategory收起状态显示的文字
    gWin.cbxCategory = ttk.Combobox(gWin, textvariable=gWin.category)
    gWin.cbxCategory["values"] = ("锅底", "佐料", "菜品")  # 下拉时显示的表象
    gWin.cbxCategory["state"] = "readonly"  # 将gWin.cbxCategory设置为不可输入，只能选择
    gWin.cbxCategory.current(0)  # 缺省时选中第0项，即显示锅底
    gWin.cbxCategory.grid(row=1, column=0, sticky="EW")  # 这个下拉列表框摆放的位置及方式
    # 以下为生成菜品、锅底、佐料的备选项
    # 生成一个listbox空间，选择模式为single，即单选
    gWin.lsbDishes = tk.Listbox(gWin, selectmode=tk.SINGLE, exportselection=False)
    # exportselection使得列表框失去输入焦点也能保持选中项目（即始终保持选中状态）
    # 添加这个列表框元素的事件响应函数，首先添加的双击的响应函数，与点击添加按钮的响应函数相同
    gWin.lsbDishes.bind("<Double-Button-1>", lambda e: btAdd_click())
    # 当这个listbox被选中时，其响应函数为将菜品数量设置为1
    gWin.lsbDishes.bind("<<ListboxSelect>>", lambda e: gWin.dishNum.set("1"))
    # 初始时，由于下拉菜单选中为锅底，因此初始时，将锅底的菜单内容装入isbdishes
    addToListbox(gWin.lsbDishes, gDishes[0])  # 装入锅底菜单
    gWin.lsbDishes.select_set(0, 0)  # select_set(x,y)可以选中第x项到第y项(包括y)
    gWin.lsbDishes.grid(row=2, column=0, sticky="EWNS")
    gWin.cbxCategory.bind("<<ComboboxSelected>>", categoryChanged)
    # 当组合框下拉后有表现被选中时，会发生ComboboxSelected事件，即更换isbdishes中的菜单
    # 此处指定该事件发生时，会调用gWin.categoryChanged函数
    # 指定"<<ComboboxSelected>>"事件的响应函数是gWin.categoryChanged
    # 以下为生成lsbtable，即我选中的菜品的列表框
    # 同样是生成一个listbox，选择模式为多选
    gWin.lsbTable = tk.Listbox(gWin, selectmode=tk.EXTENDED, exportselection=False)
    gWin.lsbTable.grid(row=2, column=2, sticky="EWNS")
    # 生成一个标签，我的餐桌
    tk.Label(gWin, text="我的餐桌").grid(row=1, column=2)
    # 生成一个标签，饭菜总价
    gWin.lbHint = tk.Label(gWin, text="饭菜总价：0元")
    # 确定标签的放置位置
    gWin.lbHint.grid(row=3, column=0, sticky="W")
    # 生成一个标签，当前账户余额
    gWin.lbmoney = tk.Label(gWin, text="账户余额：0元")
    # 确定标签的放置位置
    gWin.lbmoney.grid(row=3, column=2, sticky='W')
    # 放置一个登录按钮，登录后可以若是会员，可以享受会员价与vip价格
    lbsignup = tk.Button(gWin, text="登录", command=signin)
    lbsignup.grid(row=1, column=1, sticky="EW")
    # 放置一个结算按钮，选好菜品后可以直接结算，等待上菜
    lbpurchase = tk.Button(gWin, text="结算", command=purchase)
    lbpurchase.grid(row=3, column=1, sticky="EW")
    # 生成一个卷滚条，用于在我的菜品选择过多时上下滑动选择
    # 卷滚条是上下滑动，orient设置为vertical，时间响应函数为gWin.lsbTable.yview
    scrollbar = tk.Scrollbar(gWin, width=20, orient="vertical",
                             command=gWin.lsbTable.yview)
    # 绑定listbox和scrollbar，使卷滚条滑动的时候列表框的内容会改变
    gWin.lsbTable.configure(yscrollcommand=scrollbar.set)
    # 放置卷滚条
    scrollbar.grid(row=2, column=3, sticky="NS")
    # 放置一个frame控件，对中间部分的控件放置做安排
    frm = tk.Frame(gWin)
    # 设置框架放置的位置
    frm.grid(row=2, column=1)
    # 在frame的第0行和第0列放置一个标签，数量
    tk.Label(frm, text="数量：").grid(row=0, column=0)
    # 设置菜品数量的变量，设置为字符串类型，放置在一个spinbox中
    gWin.dishNum = tk.StringVar(value="1")
    # 设置一个spinbox控件，控件中显示的变量显示的范围为1到1000，显示的变量为我们之前定义的变量dishnum
    gWin.spNum = tk.Spinbox(frm, width=5, from_=1, to=1000,
                            textvariable=gWin.dishNum)
    # 放置这个spinbox
    gWin.spNum.grid(row=0, column=1)
    # 放置一个按钮控件，响应函数为btADD_click
    btAdd = tk.Button(frm, text="添加", command=btAdd_click)
    # 放置btadd这个按钮控件
    btAdd.grid(row=1, column=0, columnspan=2, sticky="EW")
    # 放置删除按钮，相应函数为btdelete
    btDelete = tk.Button(frm, text="删除", command=btDelete_click)
    btDelete.grid(row=2, column=0, columnspan=2, sticky="EW")
    # 放置一个labelframe控件
    lbfDiscount = tk.LabelFrame(frm, text="价格")
    lbfDiscount.grid(row=3, column=0, columnspan=2)
    # 将三个单选框全部绑定在同一个变量，当相应的单选框被选中，该变量也会改变为相应的值
    gWin.custom = tk.IntVar()  # 如果写 gWin.custom = tk.IntVar(value=0)就不用下一行了
    gWin.custom.set(0)
    # 放置第一个单选框，普通价，事件响应函数为dodiscount
    gWin.rb1 = tk.Radiobutton(lbfDiscount, text="普通价", value=0,
                              variable=gWin.custom, command=doDiscount)
    gWin.rb1.grid(row=0, column=0, sticky="W")
    # 放置第二个单选框，会员价，初始时设置为不可点击，事件响应函数为dodiscount
    gWin.rb2 = tk.Radiobutton(lbfDiscount, text="会员价(九折)",
                              value=1, variable=gWin.custom, command=doDiscount, state="disabled")
    gWin.rb2.grid(row=1, column=0, sticky="W")
    # 放置第三个单选框，vip价，初始时设置为不可点击，事件响应函数为dodiscount
    gWin.rb3 = tk.Radiobutton(lbfDiscount, text="VIP价(八折)",
                              value=2, variable=gWin.custom, command=doDiscount, state="disabled")
    gWin.rb3.grid(row=2, column=0, sticky="W")
    gWin.columnconfigure(0, weight=1)
    gWin.columnconfigure(2, weight=1)
    gWin.rowconfigure(2, weight=1)
    gWin.mainloop()


# 调用主函数
main()
