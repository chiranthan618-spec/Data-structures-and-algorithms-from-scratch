import cv2
import numpy as np

img = cv2.imread("nature.jpg")

gausssian = cv2.GaussianBlur(img, (9,9), 0)
median = cv2.medianBlur(img, 9)
combined = np.hstack((img, gausssian, median))
cv2.imshow("Original | Gaussian | Median", combined)

cv2.waitKey(0)
cv2.destroyAllWindows

