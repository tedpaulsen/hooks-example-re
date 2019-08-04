let url = region => {
  "https://api.openbrewerydb.org/breweries?by_state="
  ++ Js.String.replaceByRe([%re "/\\s/g"], "_", String.lowercase(region));
};

[@react.component]
let make = (~region) => {
  let (breweries, setBreweries) = React.useState(() => [||]);

  React.useEffect1(
    () => {
      let _ =
        Js.Promise.(
          Axios.get(url(region))
          |> then_(response => {
               Js.log("got response for " ++ region);
               resolve(setBreweries(response##data));
             })
        );
      None;
    },
    [|region|],
  );

  let renderBrewery = brw => {
    <div
      key={
        brw##id;
      }> {ReasonReact.string(brw##name)} </div>;
  };

  <div className="items">
    {breweries |> Array.map(renderBrewery) |> ReasonReact.array}
  </div>;
};
