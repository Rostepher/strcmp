begin
    require 'jeweler'
        Jeweler::Tasks.new do |gemspec|
        gemspec.name = "strcmp"
        gemspec.summary = "A gem to compare strings and compute a distance or other metric between two strings."
        gemspec.description = "A simple ruby gem that is used to compute how similar two strings are to one another. It includes a fast C implementation of the jaro-winkler distance algorith and soon the levenshtein distance algorithm. More metrics on the way."
        gemspec.email = "rostepher.dev@gmail.com"
        gemspec.homepage = "http://github.com/Rostepher/strcmp"
        gemspec.authors = ["Ross Bayer"]
        gemspec.add_dependency "ffi"
        gemspec.add_development_dependency "rspec"
        gemspec.add_development_dependency "jeweler"
    end

    Jeweler::GemcutterTasks.new
rescue LoadError
    puts "Jeweler does not seem to be here... Try installing it with: gem install jeweler"
end