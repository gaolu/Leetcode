import java.util.*;

public static int[] twoSum(int[] numbers, int target) {
        HashMap numberSet = new HashMap();
        int[] result = new int[2];
        for(int i = 0; i < numbers.length; i++){
			// found
            if(!numberSet.isEmpty() && numberSet.containsKey(target - numbers[i])){
                result[0] = (Integer)numberSet.get(target - numbers[i]) + 1;
                result[1] = i + 1;
                System.out.println("found");
                return result;
            }
            else{
            	System.out.println(target - numbers[i]);
            	numberSet.put(numbers[i], i);
            }
            System.out.println(numberSet.size());
        }
        return result;
    }