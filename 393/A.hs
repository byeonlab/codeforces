f :: Int -> Int
f x | x == 2 = 0
    | otherwise = 1

getmin :: [Int] -> Int
getmin [x] = x
getmin (x:xs) 
    | (getmin xs) < x = getmin xs
    | otherwise = x

count :: String -> Char -> Int
count s c = length $ filter (\x -> x == c) s

main = do
    string <- getLine
    
    let e = quot (count string 'e') 3
    let i = quot (count string 'i') 1
    let n =  (f $ count string 'n') + (quot ((count string 'n') - 3) 2)
    let t = quot (count string 't') 1

    print $ getmin [e, i, n, t]
