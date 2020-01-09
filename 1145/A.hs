readInt :: String -> Int
readInt = read 

readInts :: String -> [Int]
readInts x = map read $ words x

isSorted :: (Ord a) => [a] -> Bool
isSorted xs = all id . map (\(x,y) -> x <= y) . zip xs $ tail xs
 
bigger :: Int -> Int -> Int
bigger x y | (x > y) == True = x
           | (x <= y) == True = y
 
solve :: [Int] -> Int -> Int
solve x y | isSorted x == True = y
          | isSorted x == False = bigger (solve (take len x) len) (solve (drop len x) len)
            where len = y `div`  2
 
main = do
    cnt  <- getLine
    nums <- getLine
 
    let len = readInt cnt
    let list = readInts nums
    let ans = solve list len
    
    print ans

