import pandas as pd
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
import seaborn as sns
import matplotlib.pyplot as plt

df = pd.read_csv("https://raw.githubusercontent.com/mwaskom/seaborn-data/master/iris.csv")

features = df[['sepal_length', 'sepal_width', 'petal_length', 'petal_width']]
scaled_features = StandardScaler().fit_transform(features)

kmeans = KMeans(n_clusters=3, random_state=42)
df['cluster'] = kmeans.fit_predict(scaled_features)

plt.figure(figsize=(8, 6))
sns.scatterplot(
    x='petal_length', y='petal_width',
    hue='cluster', palette='Set1',
    data=df, s=100, edgecolor='black'
)
plt.title("K-Means Clustering of Iris Dataset")
plt.xlabel("Petal Length")
plt.ylabel("Petal Width")
plt.legend(title='Cluster')
plt.grid(True)
plt.tight_layout()
plt.show()
