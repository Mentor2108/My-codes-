import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt
# path = r"D:\Everything\Coding\My Codes\Python\Project\input.jpg"

img = cv.imread('D:\Everything\Coding\My Codes\Python\Project\download.jfif', 0)
# kernel = np.ones((5, 5), np.uint8)
# img_erosion = cv.erode(img, kernel, iterations = 1)
# img_dilation = cv.dilate(img, kernel, iterations = 1)

# cv.imshow("Input", img)
# cv.imshow("Erosion", img_erosion)
# cv.imshow("Dilation", img_dilation)

ret,thresh1 = cv.threshold(img,127,255,cv.THRESH_BINARY)
ret,thresh2 = cv.threshold(img,127,255,cv.THRESH_BINARY_INV)
ret,thresh3 = cv.threshold(img,127,255,cv.THRESH_TRUNC)
ret,thresh4 = cv.threshold(img,127,255,cv.THRESH_TOZERO)
ret,thresh5 = cv.threshold(img,127,255,cv.THRESH_TOZERO_INV)
titles = ['Original Image','BINARY','BINARY_INV','TRUNC','TOZERO','TOZERO_INV']
images = [img, thresh1, thresh2, thresh3, thresh4, thresh5]
for i in range(6):
    plt.subplot(2,3,i+1),plt.imshow(images[i],'gray',vmin=0,vmax=255)
    plt.title(titles[i])
    plt.xticks([]),plt.yticks([])
plt.show()

cv.waitKey(0)