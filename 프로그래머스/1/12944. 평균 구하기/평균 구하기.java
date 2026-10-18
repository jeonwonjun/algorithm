import java.util.*;
import java.util.stream.*;
 
class Solution {
    public double solution(int[] arr) {
        return Arrays.stream(arr)
            .average()
            .getAsDouble();
    }
}