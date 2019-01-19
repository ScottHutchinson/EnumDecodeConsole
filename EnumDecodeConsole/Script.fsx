open System
open System.Text

let appendIgnore (sb : StringBuilder) (txt : string) = 
    sb.Append txt |> ignore

let listToStringBuilder (sb : StringBuilder) f lst =
    sb.Clear() |> ignore
    lst |> List.iter (fun x -> appendIgnore sb (f x))


let fmt:Printf.StringFormat<_> = @"const string sDecode_ACTIVATION_TYPE%d(const int /*idx*/) { return ""x""; }"
let intToString i =
    sprintf fmt i

let sb = StringBuilder()
let n = 2000

let addFunctions sb =
    List.init n intToString
    |> listToStringBuilder sb (fun x -> sprintf "%s\r\n" x)

addFunctions sb
