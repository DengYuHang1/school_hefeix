from sklearn import tree
import numpy as np
#特征数据，可供训练的数据集一共有14个数据，每个数据有4个特征
"""
认为：
outlook:sunny为1，overcast为2，rain为3
temperature：hot为1，mild为2，cool为3
humidity：high为1，normal为2
wind：weak为1，strong为2
"""
data = np.array([[1,1,1,1],
                 [1,1,1,2],
                 [2,1,1,1],
                 [3,2,1,1],
                 [3,3,2,1],
                 [3,3,2,2],
                 [2,2,2,2],
                 [1,2,1,1],
                 [1,3,2,1],
                 [3,2,2,1],
                 [1,2,1,2],
                 [2,2,1,2],
                 [2,1,2,1],
                 [3,2,1,2]])
#加载类别标签，认为yes为1，no为0
decision_data = np.array([2,2,1,1,1,2,1,2,1,1,1,1,1,2])

#添加每个特征的名字
featureName = ['outlook','temperature','humidity','wind']
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

