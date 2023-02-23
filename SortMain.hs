module Main where

import Data.List (sort)

-- Define the quicksort function to sort a list in ascending order
quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort (filter (<= x) xs) ++ [x] ++ quickSort (filter (> x) xs)

-- Define the merge sort function to sort a list in ascending order
mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort left) (mergeSort right)
  where
    (left, right) = splitAt (length xs `div` 2) xs
    merge [] ys = ys
    merge xs [] = xs
    merge (x:xs) (y:ys)
      | x <= y    = x : merge xs (y:ys)
      | otherwise = y : merge (x:xs) ys

-- Define a main function to test the quicksort and mergesort functions
main :: IO ()
main = do
  -- Test quicksort with some sample inputs
  let unsortedList1 = [5, 5, 1, 9, 3, 7, 2, 8, 4, 6]
  putStrLn $ "Unsorted list 1: " ++ show unsortedList1
  let sortedList1 = quickSort unsortedList1
  putStrLn $ "Sorted list 1 using quicksort: " ++ show sortedList1

  let unsortedList2 = [3.5, 2.7, 1.2, 4.1, 5.8]
  putStrLn $ "Unsorted list 2: " ++ show unsortedList2
  let sortedList2 = quickSort unsortedList2
  putStrLn $ "Sorted list 2 using quicksort: " ++ show sortedList2

  let unsortedList3 = "haskell"
  putStrLn $ "Unsorted list 3: " ++ show unsortedList3
  let sortedList3 = quickSort unsortedList3
  putStrLn $ "Sorted list 3 using quicksort: " ++ show sortedList3

  let unsortedList4 = ([] :: [Int])
  putStrLn $ "Unsorted list 4: " ++ show unsortedList4
  let sortedList4 = quickSort unsortedList4
  putStrLn $ "Sorted list 4 using quicksort: " ++ show sortedList4

  -- Test mergesort with the same sample inputs
  putStrLn "-------------------------"
  putStrLn "Testing merge sort:"
  let unsortedList5 = [5, 1, 9, 3, 7, 2, 8, 4, 6, 5]
  putStrLn $ "Unsorted list 5: " ++ show unsortedList5
  let sortedList5 = mergeSort unsortedList5
  putStrLn $ "Sorted list 5: " ++ show sortedList5

  let unsortedList6 = [3.5]
  putStrLn $ "Unsorted list 6: " ++ show unsortedList6
  let sortedList6 = mergeSort unsortedList6
  putStrLn $ "Sorted list 6: " ++ show sortedList6

  let unsortedList7 = ([] :: [Int])
  putStrLn $ "Unsorted list 7: " ++ show unsortedList7
  let sortedList7 = mergeSort unsortedList7
  putStrLn $ "Sorted list 7: " ++ show sortedList7

