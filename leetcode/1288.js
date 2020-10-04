/**
 * @param {number[][]} intervals
 * @return {number}
 */
var removeCoveredIntervals = function(intervals) {
    intervals.sort(function(a,b){ if(a[0]!=b[0]) return a[0]-b[0]; else return b[1]-a[1]; })

    let ans = intervals.length;
    let last = -1;
    
    for(let i = 0; i < intervals.length; i++){
        let r = intervals[i][1];
        if(last >= r) ans--;
        if(last < r) last = r;
    }
    
    return ans;
};
