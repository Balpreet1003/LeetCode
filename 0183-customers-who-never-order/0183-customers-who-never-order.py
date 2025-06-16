import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    merge_df = pd.merge(customers,orders,how='left',left_on='id',right_on='customerId')

    return merge_df[merge_df['customerId'].isna()][['name']].rename(columns={'name':'Customers'})