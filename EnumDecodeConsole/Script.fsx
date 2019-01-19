open System
open System.Text

let appendIgnore (sb : StringBuilder) (txt : string) = 
    sb.Append txt |> ignore

let listToStringBuilder (sb : StringBuilder) f lst =
    sb.Clear() |> ignore
    lst |> List.iter (fun x -> appendIgnore sb (f x))

let sb = StringBuilder()
let n = 2000

let replicate sb f =
    List.init n f
    |> listToStringBuilder sb (fun x -> sprintf "%s\r\n" x)

let intToString fmt i =
    sprintf fmt i

//let fmt:Printf.StringFormat<_> = @"const string sDecode_ACTIVATION_TYPE%d(const int /*idx*/) { return ""x""; }"
//replicate sb (intToString fmt)

//let intToString' fmt i =
//    sprintf fmt i i

let fmt':Printf.StringFormat<_> = @"        { ""ACTIVATION_TYPE%d"", nullptr },"
replicate sb (intToString fmt')
