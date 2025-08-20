from sklearn import tree
import numpy as np

"""
认为：
是否有其他选择：是为1，否为2
饿否：是为1，否为2
价格：$为1，$$为2，$$$为3
餐馆类型：法式为1，中餐为2，快餐为3，意大利式为4
餐馆顾客人数：无人为1，有人为2，客满为3
等待时间：0-10为1，10-30为2，30-60为3，60以上为4
"""
data = np.array([[1,1,3,1,2,1],
                 [1,1,1,2,3,3],
                 [2,2,1,3,2,1],
                 [1,1,1,2,3,2],
                 [1,2,3,1,3,4],
                 [2,1,2,4,2,1],
                 [2,2,1,3,1,1],
                 [2,1,2,2,2,1],
                 [2,2,1,3,3,4],
                 [1,1,3,4,3,2],
                 [1,2,1,2,1,1],
                 [2,1,1,3,3,3]
                 ])
#加载类别标签，认为是为1，否为2
decision_data = np.array([1,2,1,1,2,1,2,1,2,2,2,1])

#添加每个特征的名字
featureName = ['selection','hungry','price','restaurant','customers','wait']
"""
调用sklearn库的决策树算法进行训练，考虑到最终输出是一个二分标签
因此使用决策树分类算法，采用信息增益来构造决策树，criterion
参数使用entropy
"""
clf = tree.DecisionTreeClassifier(criterion='entropy')
#拟合数据
clf = clf.fit(data,decision_data)
#绘制决策树
tree.plot_tree(clf,feature_names = featureName)

