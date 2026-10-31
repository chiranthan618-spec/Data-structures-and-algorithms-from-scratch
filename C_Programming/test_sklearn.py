from sklearn.datasets import load_iris
iris_dataset = load_iris()
print(iris_dataset['DESCR'][:193]+"\n...")
print("Target names: ", format(iris_dataset['target_names']))
print("feature names: ", format(iris_dataset['feature_names']))
print("the whole data stored in ndarray",format(type(iris_dataset['data'])))
print(format(iris_dataset['data'][:5]))
print("Target is a one dimensional array with one entry per flower!", format(iris_dataset['target']))

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(iris_dataset['data'], iris_dataset['target'], random_state=0)

print("X_train_shape", format(X_train.shape))
print("Y_train_shape: ", format(y_train.shape))

print("X_test: ", format(X_test.shape))
print("Y_test", format(y_test.shape))

import pandas as pd
iris_dataFrame = pd.DataFrame(X_train, columns=iris_dataset.feature_names)
grr = pd.scatter_matrix(iris_dataFrame, cc = y_train, figsize = ())