let url = region => {
  "https://api.openbrewerydb.org/breweries?by_state="
  ++ Js.String.replaceByRe([%re "/\\s/g"], "_", String.lowercase(region));
};

[@react.component]
let make = (~region) => {
  let (breweries, setBreweries) = React.useState(() => []);

  React.useEffect1(
    () => {
      Js.log2("running effect", region)
      Js.Promise.(
        Axios.get(url(region))
        |> then_(response => resolve(setBreweries(response##data)))
        |> catch(error => resolve(Js.log(error)))
      );
      None;
    },
    [|region|],
  );

  <div>
    // {breweries
    //  |> List.map(b => <div> {ReasonReact.string("b")} </div>)
    //  |> Array.of_list
    //  |> ReasonReact.array}
  </div>;
};
