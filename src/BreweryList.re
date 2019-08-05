[@bs.deriving abstract]
type brewery = {
  id: int,
  name: string,
  brewery_type: string,
  street: string,
  city: string,
  state: string,
  postal_code: string,
  country: string,
  longitude: string,
  latitude: string,
  phone: string,
  website_url: string,
  updated_at: string,
  tag_list: array(string),
};

let url = region => {
  "https://api.openbrewerydb.org/breweries?by_state="
  ++ Js.String.replaceByRe([%re "/\\s/g"], "_", String.lowercase(region));
};

[@react.component]
let make = (~region) => {
  let (breweries: array(brewery), setBreweries) = React.useState(() => [||]);

  React.useEffect1(
    () => {
      let _ =
        Js.Promise.(
          Axios.get(url(region))
          |> then_(response => resolve(setBreweries(response##data)))
        );
      None;
    },
    [|region|],
  );

  let renderBrewery = (brw: brewery) => {
    <div key={string_of_int(brw->idGet)}>
      {ReasonReact.string(brw->nameGet)}
    </div>;
  };

  <div className="items">
    {breweries |> Array.map(renderBrewery) |> ReasonReact.array}
  </div>;
};
