import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori, association_rules

transactions = [
    ['milk', 'bread', 'nuts', 'apple'],
    ['milk', 'bread'],
    ['milk', 'bread', 'nuts'],
    ['bread', 'nuts'],
    ['milk', 'apple'],
    ['milk', 'bread', 'nuts', 'apple'],
    ['bread', 'apple'],
    ['milk', 'nuts'],
    ['bread', 'nuts'],
    ['milk', 'bread', 'apple']
]

te = TransactionEncoder()
df = pd.DataFrame(te.fit_transform(transactions), columns=te.columns_)

frequent_itemsets = apriori(df, min_support=0.2, use_colnames=True)
rules = association_rules(frequent_itemsets, metric="lift", min_threshold=1.0)

filtered_rules = rules[
    (rules['confidence'] >= 0.2) &
    (rules['lift'] >= 1.2) &
    (rules.apply(lambda row: len(row['antecedents'].union(row['consequents'])) >= 2, axis=1))
]

print("📋 Association Rules:")
if not filtered_rules.empty:
    for _, rule in filtered_rules.iterrows():
        print(f"Rule: {set(rule['antecedents'])} → {set(rule['consequents'])}")
        print(f"Support: {rule['support']:.4f}")
        print(f"Confidence: {rule['confidence']:.4f}")
        print(f"Lift: {rule['lift']:.4f}")
        print("-" * 40)
else:
    print("No rules found with current filters.")
