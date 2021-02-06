import cv2
import numpy as np
S=[[0x63,0x7C,0x77,0x7B,0xF2,0x6B,0x6F,0xC5,
0x30,0x01,0x67,0x2B,0xFE,0xD7,0xAB,0x76],
[0xCA,0x82,0xC9,0x7D,0xFA,0x59,0x47,0xF0,
0xAD,0xD4,0xA2,0xAF,0x9C,0xA4,0x72,0xC0],
[0xB7,0xFD,0x93,0x26,0x36,0x3F,0xF7,0xCC,
0x34,0xA5,0xE5,0xF1,0x71,0xD8,0x31,0x15],
[0x04,0xC7,0x23,0xC3,0x18,0x96,0x05,0x9A,
0x07,0x12,0x80,0xE2,0xEB,0x27,0xB2,0x75],
[0x09,0x83,0x2C,0x1A,0x1B,0x6E,0x5A,0xA0,
0x52,0x3B,0xD6,0xB3,0x29,0xE3,0x2F,0x84],
[0x53,0xD1,0x00,0xED,0x20,0xFC,0xB1,0x5B,
0x6A,0xCB,0xBE,0x39,0x4A,0x4C,0x58,0xCF],
[0xD0,0xEF,0xAA,0xFB,0x43,0x4D,0x33,0x85,
0x45,0xF9,0x02,0x7F,0x50,0x3C,0x9F,0xA8],
[0x51,0xA3,0x40,0x8F,0x92,0x9D,0x38,0xF5,
0xBC,0xB6,0xDA,0x21,0x10,0xFF,0xF3,0xD2],
[0xCD,0x0C,0x13,0xEC,0x5F,0x97,0x44,0x17,
0xC4,0xA7,0x7E,0x3D,0x64,0x5D,0x19,0x73],
[0x60,0x81,0x4F,0xDC,0x22,0x2A,0x90,0x88,
0x46,0xEE,0xB8,0x14,0xDE,0x5E,0x0B,0xDB],
[0xE0,0x32,0x3A,0x0A,0x49,0x06,0x24,0x5C,
0xC2,0xD3,0xAC,0x62,0x91,0x95,0xE4,0x79],
[0xE7,0xC8,0x37,0x6D,0x8D,0xD5,0x4E,0xA9,
0x6C,0x56,0xF4,0xEA,0x65,0x7A,0xAE,0x08],
[0xBA,0x78,0x25,0x2E,0x1C,0xA6,0xB4,0xC6,
0xE8,0xDD,0x74,0x1F,0x4B,0xBD,0x8B,0x8A],
[0x70,0x3E,0xB5,0x66,0x48,0x03,0xF6,0x0E,
0x61,0x35,0x57,0xB9,0x86,0xC1,0x1D,0x9E],
[0xE1,0xF8,0x98,0x11,0x69,0xD9,0x8E,0x94,
0x9B,0x1E,0x87,0xE9,0xCE,0x55,0x28,0xDF],
[0x8C,0xA1,0x89,0x0D,0xBF,0xE6,0x42,0x68,
0x41,0x99,0x2D,0x0F,0xB0,0x54,0xBB,0x16]]
RC = [1, 2, 4, 8, 16, 32, 64, 128, 27, 54]
T1 = S
T2 = [[198, 248, 238, 246, 228, 214, 222, 138, 96, 2, 206, 86, 252, 174, 86, 236], [148, 4, 146, 250, 244, 178, 142, 224, 90, 168, 68, 94, 56, 72, 228, 128], [110, 250, 38, 76, 108, 126, 238, 152, 104, 74, 202, 226, 226, 176, 98, 42], [8, 142, 70, 134, 48, 44, 10, 52, 14, 36, 0, 196, 214, 78, 100, 234], [18, 6, 88, 52, 54, 220, 180, 64, 164, 118, 172, 102, 82, 198, 94, 8], [166, 162, 0, 218, 64, 248, 98, 182, 212, 150, 124, 114, 148, 152, 176, 158], [160, 222, 84, 246, 134, 154, 102, 10, 138, 242, 4, 254, 160, 120, 62, 80], [162, 70, 128, 30, 36, 58, 112, 234, 120, 108, 180, 66, 32, 254, 230, 164], [154, 24, 38, 216, 190, 46, 136, 46, 136, 78, 252, 122, 200, 186, 50, 230], [192, 2, 158, 184, 68, 84, 32, 16, 140, 220, 112, 40, 188, 188, 22, 182], [192, 100, 116, 20, 146, 12, 72, 184, 132, 166, 88, 196, 34, 42, 200, 242], [206, 144, 110, 218, 26, 170, 156, 82, 216, 172, 232, 212, 202, 244, 92, 16], [116, 240, 74, 92, 56, 76, 104, 140, 208, 186, 232, 62, 150, 122, 22, 20], [224, 124, 106, 204, 144, 6, 236, 28, 194, 106, 174, 114, 12, 130, 58, 60], [194, 240, 48, 34, 210, 178, 28, 40, 54, 60, 14, 210, 156, 170, 80, 190], [24, 66, 18, 26, 126, 204, 132, 208, 130, 50, 90, 30, 96, 168, 118, 44]]
T3 = [[41,116, 101, 113, 214, 65, 77, 79, 144, 3, 53, 129, 250, 133, 1, 98], [94, 134, 91, 119, 238, 11, 213, 208, 7, 124, 230, 13, 212, 236, 86, 64], [37, 247, 185, 114, 162, 189, 229, 100, 156, 239, 175, 211, 83, 136, 147, 63], [12, 85, 105, 73, 72, 194, 15, 206, 21, 54, 128, 166, 193, 117, 22, 95], [27, 137, 132, 78, 81, 74, 14, 224, 246, 177, 130, 25, 123, 169, 141, 140], [249, 115, 0, 199, 96, 244, 19, 17, 62, 97, 58, 171, 222, 228, 8, 109], [112, 205, 254, 241, 201, 231, 153, 143, 207, 235, 6, 125, 240, 180, 221, 248], [243, 233, 192, 173, 182, 215, 168, 223, 52, 34, 142, 99, 48, 253, 217, 118], [103, 36, 57, 196, 29, 197, 204, 69, 76, 245, 122, 183, 44, 23, 75, 89], [32, 131, 237, 148, 102, 126, 176, 152, 210, 202, 40, 60, 154, 26, 33, 145], [160, 150, 174, 30, 219, 18, 108, 20, 70, 121, 4, 38, 179, 191, 172, 107], [181, 88, 165, 71, 167, 127, 234, 251, 68, 2, 220, 190, 47, 110, 10, 24], [46, 104, 111, 138, 84, 242, 28, 82, 184, 151, 92, 93, 225, 55, 161, 158], [80, 186, 31, 50, 216, 9, 226, 42, 35, 159, 5, 43, 146, 67, 87, 218], [163, 232, 200, 51, 59, 139, 170, 188, 209, 90, 149, 187, 106, 255, 120, 157], [164, 227, 155, 39, 61, 178, 198, 56, 195, 203, 135, 45, 16, 252, 49, 66]]
reS = [[0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB],
              [0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB],
              [0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E],
              [0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25],
              [0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92],
              [0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84],
              [0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06],
              [0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B],
              [0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73],
              [0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E],
              [0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B],
              [0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4],
              [0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F],
              [0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF],
              [0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61],
              [0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D]]


def vigEncry(oriImg):
    keyWord = input("Please input the keyword:\n")
    encryImg = oriImg
    width, height, channel = encryImg.shape
    l = len(keyWord)
    k=0;
    for i in range(width):
        for j in range (height):
            for c in range(channel):
                encryImg[i,j,c]=encryImg[i, j, c]+ord(keyWord[k])
                k=(k+1)%l
    cv2.imshow("Encrypted picture", encryImg)
    key = cv2.waitKey(0)
    if key == 27:
        print(key)
        cv2.destroyAllWindows()
    cv2.imwrite("result.bmp",encryImg)


def unvigEncry(oriImg):
    keyWord = input("Please input the keyword:\n")
    unencryImg = oriImg
    width, height, channel = unencryImg.shape
    l = len(keyWord)
    k=0;
    for i in range(width):
        for j in range (height):
            for c in range(channel):
                unencryImg[i,j,c]=unencryImg[i, j, c]-ord(keyWord[k])
                k=(k+1)%l
    cv2.imshow("UnEncrypted picture", unencryImg)
    key = cv2.waitKey(0)
    if key == 27:
        print(key)
        cv2.destroyAllWindows()
    cv2.imwrite("result.bmp",unencryImg)

def keyExpand(key,keyExp):
    for i in range(4):
        for j in range(44):
            keyExp[i].append(0)
    for i in range(4):
        for j in range(4):
            keyExp[i][j]=ord(key[4*j+i])
    keyMid=[0,0,0,0]
    for i in range(4,44):
        if(i%4==0):
            for j in range(4):
                keyMid[j]=keyExp[j][i-1]
            b=keyMid[0]
            for j in range(3):
                keyMid[j]=keyMid[j+1]
            keyMid[3]=b
            for j in range(4):
                a = int(keyMid[j]/16)
                b = keyMid[j] % 16
                keyMid[j] = S[a][b]
                if(j==0):
                    keyMid[j]=keyMid[j]^RC[int(i/4)-1]
                keyExp[j][i] = keyMid[j]^keyExp[j][i-4]
        else:
            for j in range(4):
                keyExp[j][i]=keyExp[j][i-1]^keyExp[j][i-4]

def AES(Mes,keyExp):
    x=[0,0,0,0]
    y=[0,0,0,0]
    MesMid=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    for i in range(4):
        for j in range(4):
            Mes[i][j]=Mes[i][j]^keyExp[i][j]
    for k in range(9):
        for j in range(4):
            for i in range(4):
                x[i]=int(Mes[i][(j+i)%4]/16)
                y[i]=(Mes[i][(j+1)%4])%16
            MesMid[0][j]=T2[x[0]][y[0]]^T3[x[1]][y[1]]^T1[x[2]][y[2]]^T1[x[3]][y[3]]^keyExp[0][4*k+4+j]
            MesMid[1][j]=T1[x[0]][y[0]]^T2[x[1]][y[1]]^T3[x[2]][y[2]]^T1[x[3]][y[3]]^keyExp[1][4*k+4+j]
            MesMid[2][j]=T1[x[0]][y[0]]^T1[x[1]][y[1]]^T2[x[2]][y[2]]^T3[x[3]][y[3]]^keyExp[2][4*k+4+j]
            MesMid[3][j]=T3[x[0]][y[0]]^T1[x[1]][y[1]]^T1[x[2]][y[2]]^T2[x[3]][y[3]]^keyExp[3][4*k+4+j]
        for i in range(4):
            for j in range(4):
                Mes[i][j]=MesMid[i][j]
    for i in range(4):
        for j in range(4):
            a=Mes[i][j]
            Mes[i][j]=S[int(a/16)][a%16]
    for i in range(4):
        for j in range(4):
            MesMid[i][j]=Mes[i][(j+i)%4]
    for i in range(4):
        for j in range(4):
            Mes[i][j]=MesMid[i][j]^keyExp[i][40+j]

def AESEncry(oriImg):
    keyWord = input("Please input the 16 bytes keyword:\n")
    keyExp=[[],[],[],[]]
    keyExpand(keyWord,keyExp)
    encryImg=oriImg
    width,height,channel=oriImg.shape
    imgMes=[]
    for i in range(width):
        for j in range(height):
            for k in range(channel):
                imgMes.append(encryImg[i,j,k])
    imgMesLen=len(imgMes)
    Mes=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    i=0
    while(i+16<=imgMesLen):
        Mes[0] = imgMes[i: i + 4]
        Mes[1] = imgMes[i+4: i +8]
        Mes[2] = imgMes[i+8: i + 12]
        Mes[3] = imgMes[i+12: i + 16]
        AES(Mes,keyExp)
        imgMes[i:i+4]=Mes[0]
        imgMes[i+4:i + 8] = Mes[1]
        imgMes[i+8:i + 12] = Mes[2]
        imgMes[i+12:i + 16] = Mes[3]
        i=i+16
    k=0
    for i in range(width):
        for j in range(height):
            for m in range(channel):
                encryImg[i,j,m]=imgMes[k]
                k=k+1
    cv2.imshow("Encrypted picture", encryImg)
    key = cv2.waitKey(0)
    if key == 27:
        print(key)
        cv2.destroyAllWindows()
    cv2.imwrite("result.bmp", encryImg)


def unAES(Mes,keyExp):
    MesMid=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    for i in range(4):
        for j in range(4):
            Mes[i][j]=Mes[i][j]^keyExp[i][40+j]
    for k in range(9):
        for j in range(4):
            for i in range(4):
                MesMid[i][j]=Mes[i][(4+j-i)%4]
        for j in range(4):
            for i in range(4):
                Mes[i][j]=reS[int(MesMid[i][j]/16)][MesMid[i][j]%16]
        for i in range(4):
            for j in range(4):
                MesMid[i][j]=Mes[i][j]^keyExp[i][36-k*4+j]
        for j in range(4):
            Mes[0][j] = ((14 * MesMid[0][j]) % 256) ^ ((11 * MesMid[1][j]) % 256) ^ ((13 * MesMid[2][j]) % 256) ^ ((9 * MesMid[3][j]) % 256)
            Mes[1][j] = ((9 * MesMid[0][j]) % 256) ^ ((14 * MesMid[1][j]) % 256) ^ ((11 * MesMid[2][j]) % 256) ^ ((13 * MesMid[3][j]) % 256)
            Mes[2][j] = ((13 * MesMid[0][j]) % 256) ^ ((9 * MesMid[1][j]) % 256) ^ ((14 * MesMid[2][j]) % 256) ^ ((11 * MesMid[3][j]) % 256)
            Mes[3][j] = ((11 * MesMid[0][j]) % 256) ^ ((13 * MesMid[1][j]) % 256) ^ ((9 * MesMid[2][j]) % 256) ^ ((14 * MesMid[3][j]) % 256)
    for j in range(4):
        for i in range(4):
            MesMid[i][j] = Mes[i][(4 + j - i) % 4]
    for j in range(4):
        for i in range(4):
            Mes[i][j] = reS[int(MesMid[i][j] / 16)][MesMid[i][j] % 16]
    for i in range(4):
        for j in range(4):
            Mes[i][j] = Mes[i][j] ^ keyExp[i][j]
def unAESEncry(oriImg):
    keyWord = input("Please input the 16 bytes keyword:\n")
    keyExp=[[],[],[],[]]
    keyExpand(keyWord,keyExp)
    unencryImg=oriImg
    width,height,channel=oriImg.shape
    imgMes=[]
    for i in range(width):
        for j in range(height):
            for k in range(channel):
                imgMes.append(unencryImg[i,j,k])
    imgMesLen=len(imgMes)
    for i in range(15):
        imgMes.append(0)
    Mes=[[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
    i=0
    while(i+16<=imgMesLen):
        Mes[0] = imgMes[i: i + 4]
        Mes[1] = imgMes[i+4: i +8]
        Mes[2] = imgMes[i+8: i + 12]
        Mes[3] = imgMes[i+12: i + 16]
        unAES(Mes,keyExp)
        imgMes[i:i+4]=Mes[0]
        imgMes[i+4:i + 8] = Mes[1]
        imgMes[i+8:i + 12] = Mes[2]
        imgMes[i+12:i + 16] = Mes[3]
        i=i+16
    k=0
    for i in range(width):
        for j in range(height):
            for m in range(channel):
                unencryImg[i,j,m]=imgMes[k]
                k=k+1
    cv2.imshow("UnEncrypted picture", unencryImg)
    key = cv2.waitKey(0)
    if key == 27:
        print(key)
        cv2.destroyAllWindows()
    cv2.imwrite("result.bmp", unencryImg)

encryway = input("Please choose the way you prefer.1 for Vigenere and 2 for AES ")
pathFile = input("Which picture do you want to do this?")
img = cv2.imread(pathFile)
if (encryway=='1'):
        vigEncry(img)
else:
        AESEncry(img)
