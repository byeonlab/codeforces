outcomes :: String -> Int
outcomes s = 1 + length s

main = do
    count <- getLine
    s <- getLine
    let c = read count

    print $ c + 1
