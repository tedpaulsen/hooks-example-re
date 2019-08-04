let url = region => {
  "https://api.openbrewerydb.org/breweries?by_state="
  ++ Js.String.replaceByRe([%re "/\\s/g"], "_", String.lowercase(region));
};

[@react.component]
let make = (~region) => {
  let (breweries, setBreweries) = React.useState(() => []);

  React.useEffect1(
    () => {
      Js.Promise.(
        Axios.get(url(region))
        |> then_(response => {
             resolve(setBreweries(response##data));
           })
      );
      None;
    },
    [|region|],
  );

  Js.log(breweries);

  <div>
    // {
    //   breweries |>
    //   List.map(b => <div>{ReasonReact.string(b##name)}</div>) |>
    //   Array.of_list |>
    //   React.array
    // }
  </div>;
};
