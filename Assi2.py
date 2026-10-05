'''Plot Boxplots for all numerical attributes in the Wine dataset to visually identify any potential
outliers.'''
import pandas as pd 
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
data=pd.read_csv('wine.csv')
df=pd.DataFrame(data)
plt.figure(figsize=(7,5))
sns.boxplot(data=df)
plt.title("Boxplots of All Numerical Attributes")
plt.xlabel("Numerical Aattributes")
plt.ylabel("Values")
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

