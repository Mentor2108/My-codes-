import yfinance as yf
import numpy as np

data = yf.download(["HDFCBANK.NS","ICICIBANK.NS","AXISBANK.NS","KOTAKBANK.NS"],start="2020-06-01", end = "2022-11-30")

N = 624 #Number of Rows
for i in range(624):
    data.iloc[i,0] = (data.iloc[i,0])*0.2    # 0.2 allocation
    data.iloc[i,1] = (data.iloc[i,1])*0.3    # 0.3 allocation
    data.iloc[i,2] = (data.iloc[i,2])*0.2    # 0.2 allocation
    data.iloc[i,3] = (data.iloc[i,3])*0.3    # 0.3 allocation 


closes = data['Adj Close']
closes.columns = ['AXISB','HDFCB','ICICIB','KOTAKB']
AXISB_returns = closes.AXISB.pct_change().dropna()
HDFCB_returns = closes.HDFCB.pct_change().dropna()
ICICIB_returns = closes.ICICIB.pct_change().dropna()
KOTAKB_returns = closes.KOTAKB.pct_change().dropna()

def sortino_ratio(returns, adjustment_factor=0.0):
    returns_risk_adj = np.asanyarray(returns - adjustment_factor)
    mean_annual_return = returns_risk_adj.mean() * 252

    # compute the downside deviation
    downside_diff = np.clip(returns_risk_adj, np.NINF, 0)
    np.square(downside_diff, out=downside_diff)
    annualized_downside_deviation = np.sqrt(downside_diff.mean()) * np.sqrt(252)

    return mean_annual_return / annualized_downside_deviation

def sharpe_ratio(returns, adjustment_factor=0.0):
    returns_risk_adj = returns - adjustment_factor
    return ( returns_risk_adj.mean() / returns_risk_adj.std() ) * np.sqrt(252)

print("------AXIS BANK------\nSortino Ratio: ", sortino_ratio(AXISB_returns,adjustment_factor=0.0))
print("Sharpe Ratio: ", sharpe_ratio(AXISB_returns,adjustment_factor=0.0))
print("\n\n------HDFC BANK------")
print("Sortino Ratio: ", sortino_ratio(HDFCB_returns,adjustment_factor=0.0))
print("Sharpe Ratio: ", sharpe_ratio(HDFCB_returns,adjustment_factor=0.0))
print("\n\n------ICICI BANK------")
print("Sortino Ratio: ", sortino_ratio(ICICIB_returns,adjustment_factor=0.0))
print("Sharpe Ratio: ", sharpe_ratio(ICICIB_returns,adjustment_factor=0.0))
print("\n\n------KOTAK BANK------")
print("Sortino Ratio: ", sortino_ratio(KOTAKB_returns,adjustment_factor=0.0))
print("Sharpe ratio: ", sharpe_ratio(KOTAKB_returns,adjustment_factor=0.0))
print("\n\n")

data = yf.download(["HDFCBANK.NS","ICICIBANK.NS","AXISBANK.NS","KOTAKBANK.NS"],start="2020-06-01", end = "2022-11-30")

for i in range(624):
    data.iloc[i,0] = (data.iloc[i,0])*0.2    # 0.2 allocation
    data.iloc[i,1] = (data.iloc[i,1])*0.2    # 0.2 allocation
    data.iloc[i,2] = (data.iloc[i,2])*0.3    # 0.3 allocation
    data.iloc[i,3] = (data.iloc[i,3])*0.3    # 0.3 allocation 


closes = data['Adj Close']
closes.columns = ['AXISB1','HDFCB1','ICICIB1','KOTAKB1']
AXISB_returns = closes.AXISB1.pct_change().dropna()
HDFCB_returns = closes.HDFCB1.pct_change().dropna()
ICICIB_returns = closes.ICICIB1.pct_change().dropna()
KOTAKB_returns = closes.KOTAKB1.pct_change().dropna()

print("-------------------------------FOR SECOND SET OF ALLOCATIONS-------------------------------\n")

print("------AXIS BANK------\nSortino Ratio: ", sortino_ratio(AXISB_returns,adjustment_factor=0.0))
print("Sharpe Ratio: ", sharpe_ratio(AXISB_returns,adjustment_factor=0.0))
print("\n\n------HDFC BANK------")
print("Sortino Ratio: ", sortino_ratio(HDFCB_returns,adjustment_factor=0.0))
print("Sharpe Ratio: ", sharpe_ratio(HDFCB_returns,adjustment_factor=0.0))
print("\n\n------ICICI BANK------")
print("Sortino Ratio: ", sortino_ratio(ICICIB_returns,adjustment_factor=0.0))
print("Sharpe Ratio: ", sharpe_ratio(ICICIB_returns,adjustment_factor=0.0))
print("\n\n------KOTAK BANK------")
print("Sortino Ratio: ", sortino_ratio(KOTAKB_returns,adjustment_factor=0.0))
print("Sharpe ratio: ", sharpe_ratio(KOTAKB_returns,adjustment_factor=0.0))
print("\n")

print("The ratios are equal!")