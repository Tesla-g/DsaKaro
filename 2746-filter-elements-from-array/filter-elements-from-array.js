/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filteredArr=[];
    for(let i=0;i<arr.length;i++){
        const isTrue=fn(arr[i],i);
        if(isTrue){
            filteredArr.push(arr[i]);
        }
       
    }
     return filteredArr
};