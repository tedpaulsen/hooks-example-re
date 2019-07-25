// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var BreweryList$ReactHooksTemplate = require("./BreweryList.bs.js");

var allRegions = /* array */[
  "Alabama",
  "Alaska",
  "Arizona",
  "Arkansas",
  "California",
  "Colorado",
  "Connecticut",
  "Delaware",
  "Florida",
  "Georgia",
  "Hawaii",
  "Idaho",
  "Illinois",
  "Indiana",
  "Iowa",
  "Kansas",
  "Kentucky",
  "Louisiana",
  "Maine",
  "Maryland",
  "Massachusetts",
  "Michigan",
  "Minnesota",
  "Mississippi",
  "Missouri",
  "Montana",
  "Nebraska",
  "Nevada",
  "New Hampshire",
  "New Jersey",
  "New Mexico",
  "New York",
  "North Carolina",
  "North Dakota",
  "Ohio",
  "Oklahoma",
  "Oregon",
  "Pennsylvania",
  "Rhode Island",
  "South Carolina",
  "South Dakota",
  "Tennessee",
  "Texas",
  "Utah",
  "Vermont",
  "Virginia",
  "Washington",
  "West Virginia",
  "Wisconsin",
  "Wyoming"
];

function App(Props) {
  var match = React.useState((function () {
          return Caml_array.caml_array_get(allRegions, 0);
        }));
  var setRegion = match[1];
  var region = match[0];
  return React.createElement("div", undefined, React.createElement("select", {
                  value: region,
                  onChange: (function (e) {
                      return Curry._1(setRegion, e.target.value);
                    })
                }, $$Array.map((function (r) {
                        return React.createElement("option", {
                                    key: r,
                                    value: r
                                  }, r);
                      }), allRegions)), React.createElement(BreweryList$ReactHooksTemplate.make, {
                  region: region
                }));
}

var make = App;

exports.allRegions = allRegions;
exports.make = make;
/* react Not a pure module */
