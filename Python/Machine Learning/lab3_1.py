# -*- coding: utf-8 -*-
"""
Created on Fri Nov 17 17:41:44 2023

@author: K Tejashree
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd 
dataset= pd.read_csv('C:/Users/K Tejashree/.spyder-py3/data_ml/iris.csv')
dataset.describe()
dataset.info()
#Splitting the dataset into Training set and Test set 
X = dataset.iloc[:, 0:4].values 
#X = dataset.ilot[:.[1,2, 3]].values
y = dataset.iloc[:,4].values
""" Iriis -sentosa correspond to 0 ,Iris-versicolor correspond to 1 and Iris-viginica correspond to 2
"""           
from sklearn.preprocessing import LabelEncoder 
le = LabelEncoder()
y= le.fit_transform(y)

from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)
#if random state is changed then accuracy differs

# Festure Scaling
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()

X_train  = sc.fit_transform(X_train)
X_test =sc.transform(X_test)


from sklearn.metrics import accuracy_score,precision_score,recall_score
from sklearn.metrics import f1_score,confusion_matrix

#fitting Naive Bayes Classification to the Training set with linear kernel 
from sklearn.naive_bayes import GaussianNB
classifier = GaussianNB()
classifier.fit(X_train, y_train)
# predicting the Test set results
y_pred = classifier.predict(X_test)

cm = confusion_matrix(y_test,y_pred)
cm

accuracy = accuracy_score(y_test, y_pred)
precision = precision_score(y_test, y_pred,average='micro')
recall = recall_score(y_test, y_pred,average='micro')
f1 = f1_score(y_test, y_pred,average='micro')
print('Confusion matrix for Naive Bayes\n',cm)
print('accuracy_Naive Bayes:%.3f' %accuracy)
print('precision_Naive Bayes:%.3f' %precision)
print('recall_Naive Bayes:%.3f' %recall)
print('fl-score_Naive Bayes:%.3f' %f1)




























