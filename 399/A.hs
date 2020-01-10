import Control.Monad

printConcat :: Show a => [a] -> IO ()
printConcat = putStrLn . concat . map show

readInts :: String -> [Int]
readInts x = map read $ words x

paginate :: Int -> Int -> Int -> [Int]
paginate n p k = filter (\x -> (x >= p - k) && (x <= p + k)) [1..n]


paginate' :: [char] -> [char] -> [char] -> [char]
paginate' n p k = filter (\x -> (x >= p - k) && (x <= p + k)) [1..n]

main = do
    input <- getLine

    let n = (readInts input)!!0
    let p = (readInts input)!!1
    let k = (readInts input)!!2

    let pages = paginate n p k

    when (head pages /= 1)  $ putStr (id "<< ")
    --mapM_ print pages
    mapM_ (putStr .  show) pages
    when (last pages /= n)  $ putStr (id " >>")
