import pandas as pd

df = pd.read_csv("StudentsPerformance.csv")

print("📐 Shape of the dataset (rows, columns):", df.shape)

print("\n🔝 Top 5 rows of the dataset:")
print(df.head())

num_random_rows = 5
print(f"\n🎲 {num_random_rows} Random rows from the dataset:")
print(df.sample(num_random_rows))

print("\n📊 Number of columns:", len(df.columns))
print("📝 Column names:")
print(df.columns.tolist())
