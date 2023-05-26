/* This function search binary in an array */
int binarySearch(int length, int a[], int target) { 
   int left = 0;
   int right = length; 
   /* Loop until the indexes aren't the same */
   while (left < right - 1) { //until the indexes aren't the same
      int mid = (left + right) / 2; // mid = left + (right - left) / 2;
      /* If the target is smaller than the middle */
      if (target < a[mid]) { 
         /* Middle is assgined to the right bound */
         right = mid; 
      } else {
         /* Middle is assgined to the left bound */
         left = mid; 
      }
   }
   /* The case when the target is found */
   if ((left < length) && (a[left] == target)) { 
      return 1;
   }
   return 0;
}