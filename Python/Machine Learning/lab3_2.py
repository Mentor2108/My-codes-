# -*- coding: utf-8 -*-
"""
Created on Fri Nov 17 18:15:16 2023

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


#fitting classifier to the Training set 
#loading libraries 
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix,accuracy_score
from sklearn.model_selection import cross_val_score

# Instantiate learning model(k = 3)
classifier = KNeighborsClassifier(n_neighbors=11)
#Fitting the model
classifier.fit(X_train,y_train)

#Predicting the Test set results 
y_pred = classifier.predict(X_test)

cm = confusion_matrix(y_test,y_pred)
cm

from sklearn.metrics import accuracy_score

per = accuracy_score(y_test, y_pred)
print("Accuracy",per)
