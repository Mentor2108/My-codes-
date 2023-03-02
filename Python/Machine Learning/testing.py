import matplotlib.pyplot as plt

def draw_tree(x, y,k):
    plt.scatter(x, y, s=400, c='pink', edgecolors='blue', alpha=1)
    if (k!=4):
      plt.plot([x, x], [y-0.9, y-0.1], c='black', lw=2)

    
x_positions = [20, 20, 20, 20]
y_positions = [0, -1, -2, -3]
k=0
for x, y in zip(x_positions, y_positions):
    k+=1
    draw_tree(x, y,k)

plt.axis('off')
plt.show()