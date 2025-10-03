public class Main {
    public static void main(String[] args) {
        boolean allPassed = true;

        try {
            // Test 1: Initial size and capacity
            DynamicArray<Integer> arr = new DynamicArray<>(2);
            allPassed &= check(arr.getSize() == 0, "Initial size");
            allPassed &= check(arr.getCapacity() == 2, "Initial capacity");

            // Test 2: Pushback within capacity
            arr.pushback(10);
            arr.pushback(20);
            allPassed &= check(arr.getSize() == 2, "Size after 2 pushbacks");
            allPassed &= check(arr.getCapacity() == 2, "Capacity after 2 pushbacks");
            allPassed &= check(arr.get(0) == 10 && arr.get(1) == 20, "Get after 2 pushbacks");

            // Test 3: Pushback triggers resize
            arr.pushback(30); // triggers resize
            allPassed &= check(arr.getSize() == 3, "Size after pushback triggers resize");
            allPassed &= check(arr.getCapacity() == 4, "Capacity after resize");
            allPassed &= check(arr.get(2) == 30, "Get after resize");

            // Test 4: Set method
            arr.set(1, 25);
            allPassed &= check(arr.get(1) == 25, "Set method");

            // Test 5: Popback
            Integer popped = arr.popback();
            allPassed &= check(popped == 30, "Popback value");
            allPassed &= check(arr.getSize() == 2, "Size after popback");

            // Test 6: Multiple pushbacks and resize
            for (int i = 0; i < 10; i++) arr.pushback(i * 10);
            allPassed &= check(arr.getSize() == 12, "Size after multiple pushbacks");
            allPassed &= check(arr.getCapacity() >= 12, "Capacity after multiple pushbacks");
            allPassed &= check(arr.get(11) == 90, "Get last element after multiple pushbacks");

            // Test 7: Pop until empty
            while (arr.getSize() > 0) arr.popback();
            boolean exceptionThrown = false;
            try {
                arr.popback();
            } catch (Exception e) {
                exceptionThrown = true;
            }
            allPassed &= check(exceptionThrown, "Popback on empty array returns null or throws exception");

            // Test 8: Invalid set index
            arr.pushback(1);
            boolean setException = false;
            try {
                arr.set(5, 100);
            } catch (IndexOutOfBoundsException e) {
                setException = true;
            }
            allPassed &= check(setException, "Set with invalid index throws exception");

        } catch (Exception e) {
            allPassed = false;
            System.out.println("Unexpected exception: " + e);
        }

        System.out.println(allPassed ? "All tests passed!" : "Some tests failed!");
    }

    private static boolean check(boolean condition, String testName) {
        if (!condition) {
            System.out.println("Test failed: " + testName);
            return false;
        }
        return true;
    }
}

