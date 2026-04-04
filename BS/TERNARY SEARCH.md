# TERNARY SEARCH


 <span style="font-size: 20.0;text-align: left;">
     int ternarySearch(int l, int r, int key, int ar[])
{
    
 </span> <span style="font-size: 20.0;text-align: left;">
     **while**
 </span> <span style="font-size: 20.0;text-align: left;">
      (r >= l) {

        
 </span> <span style="font-size: 20.0;text-align: left;">
     *// Find the mid1 and mid2*
 </span> <span style="font-size: 20.0;text-align: left;">
     
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        
 </span> <span style="font-size: 20.0;text-align: left;">
     *// Check if key is present at any mid*
 </span>
         <span style="font-size: 20.0;text-align: left;">
     **if**
 </span> <span style="font-size: 20.0;text-align: left;">
      (ar[mid1] == key) {
            
 </span> <span style="font-size: 20.0;text-align: left;">
     **return**
 </span> <span style="font-size: 20.0;text-align: left;">
      mid1;
        }
        
 </span> <span style="font-size: 20.0;text-align: left;">
     **if**
 </span> <span style="font-size: 20.0;text-align: left;">
      (ar[mid2] == key) {
            
 </span> <span style="font-size: 20.0;text-align: left;">
     **return**
 </span> <span style="font-size: 20.0;text-align: left;">
      mid2;
        }

        
 </span> <span style="font-size: 20.0;text-align: left;">
     *// Since key is not present at mid,*
 </span>
         <span style="font-size: 20.0;text-align: left;">
     *// check in which region it is present*
 </span>
         <span style="font-size: 20.0;text-align: left;">
     *// then repeat the Search operation*
 </span>
         <span style="font-size: 20.0;text-align: left;">
     *// in that region*
 </span>

         <span style="font-size: 20.0;text-align: left;">
     **if**
 </span> <span style="font-size: 20.0;text-align: left;">
      (key < ar[mid1]) {

            
 </span> <span style="font-size: 20.0;text-align: left;">
     *// The key lies in between l and mid1*
 </span> <span style="font-size: 20.0;text-align: left;">
     
            r = mid1 - 1;
        }
        
 </span> <span style="font-size: 20.0;text-align: left;">
     **else**
 </span>  <span style="font-size: 20.0;text-align: left;">
     **if**
 </span> <span style="font-size: 20.0;text-align: left;">
      (key > ar[mid2]) {

            
 </span> <span style="font-size: 20.0;text-align: left;">
     *// The key lies in between mid2 and r*
 </span> <span style="font-size: 20.0;text-align: left;">
     
            l = mid2 + 1;
        }
        
 </span> <span style="font-size: 20.0;text-align: left;">
     **else**
 </span> <span style="font-size: 20.0;text-align: left;">
      {

            
 </span> <span style="font-size: 20.0;text-align: left;">
     *// The key lies in between mid1 and mid2*
 </span> <span style="font-size: 20.0;text-align: left;">
     
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    
 </span> <span style="font-size: 20.0;text-align: left;">
     *// Key not found*
 </span>
     <span style="font-size: 20.0;text-align: left;">
     **return**
 </span> <span style="font-size: 20.0;text-align: left;">
      -1;
}

 </span>