require 'spec_helper'

describe JaroWinkler do
    test_cases = [
        ["", "", 1.0],
        ["foobar", "", 0.0],
        ["martha", "marhta", 0.961],
        ["dwayne", "duane", 0.84],
        ["dixon", "dicksonx", 0.813]
    ]

    test_cases.each do |str1, str2, distance|
        it "should calculate the distance #{distance} from #{str1} and #{str2}" do
            JaroWinkler.distance(str1, str2).round(3) == distance
            JaroWinkler.distance(str2, str1).round(3) == distance
        end
    end

    it "should raise an error if either arguemnt is nil" do
        expect { JaroWinkler.distance("", nil) }.to raise_error TypeError
        expect { JaroWinkler.distance(nil, "") }.to raise_error TypeError
    end

    it "should raise an error if either argument is not a string" do
        expect { JaroWinkler.distance("foo", /bar/) }.to raise_error TypeError
        expect { JaroWinkler.distance("42", 42) }.to raise_error TypeError
        expect { JaroWinkler.distance("Object", Object.new) }.to raise_error TypeError
    end
end