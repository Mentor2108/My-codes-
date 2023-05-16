import pandas as pd
Stock = pd.DataFrame([["Lays, Tangy Tomato (50g)", 20], ["Lays, Indian Magic Masala (50g)", 20]], columns = ["Name of Item", "Price"])
Stock.to_csv("Stock.csv", index = False)