/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
 return {
     
     toBe : function (v){
         if(val===v) return true;
         else{
          throw new Error("Not Equal");
         }
     },
     notToBe: function (val2){
        if(val2===val) throw new Error('Equal');
         else{
            return true;
         }
     }
 }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */