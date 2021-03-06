// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var Axios = require("axios");
var React = require("react");
var $$String = require("bs-platform/lib/js/string.js");

function url(region) {
  return "https://api.openbrewerydb.org/breweries?by_state=" + $$String.lowercase(region).replace((/\s/g), "_");
}

function BreweryList(Props) {
  var region = Props.region;
  var match = React.useState((function () {
          return /* array */[];
        }));
  var setBreweries = match[1];
  React.useEffect((function () {
          Axios.get(url(region)).then((function (response) {
                  return Promise.resolve(Curry._1(setBreweries, response.data));
                }));
          return undefined;
        }), /* array */[region]);
  var renderBrewery = function (brw) {
    return React.createElement("div", {
                key: String(brw.id)
              }, brw.name);
  };
  return React.createElement("div", {
              className: "items"
            }, $$Array.map(renderBrewery, match[0]));
}

var make = BreweryList;

exports.url = url;
exports.make = make;
/* axios Not a pure module */
