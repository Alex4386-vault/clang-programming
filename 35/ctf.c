int main() {    
  int *arr = (int *)malloc(sizeof(int) * 100);

  arr[0] = 60;
  arr[1] = 91;
  arr[2] = 57;
  arr[3] = 92;
  arr[4] = 110;
  arr[5] = 117;
  arr[6] = 36;
  arr[7] = 46;
  arr[8] = 91;
  arr[9] = 64;
  arr[10] = 69;
  arr[11] = 64;
  arr[12] = 26;
  arr[13] = 128;
  arr[14] = 82;
  arr[15] = 102;
  arr[16] = 35;
  arr[17] = 98;
  arr[18] = 101;
  arr[19] = 108;
  arr[20] = 89;
  arr[21] = 89;
  arr[22] = 39;
  arr[23] = 70;
  arr[24] = 20;
  arr[25] = 46;
  arr[26] = 20;
  arr[27] = 128;
  arr[28] = 35;
  arr[29] = 57;
  arr[30] = 59;
  arr[31] = 61;
  arr[32] = 74;
  arr[33] = 108;
  arr[34] = 39;
  arr[35] = 111;
  arr[36] = 35;
  arr[37] = 98;
  arr[38] = 103;
  arr[39] = 108;
  arr[40] = 96;
  arr[41] = 62;
  arr[42] = 87;
  arr[43] = 81;
  arr[44] = 63;
  arr[45] = 64;
  arr[46] = 82;
  arr[47] = 128;
  arr[48] = 68;
  arr[49] = 130;
  arr[50] = 52;
  arr[51] = 127;
  arr[52] = 38;
  arr[53] = 76;
  arr[54] = 50;
  arr[55] = 76;
  arr[56] = 50;
  arr[57] = 138;
  int x = 0;
  for (int i = 0; arr[i]; ++i )
  {
    
    if ( ++x & 1 )
      putchar(arr[i] + 13);
    else
      putchar(arr[i] - 13);
  }
}