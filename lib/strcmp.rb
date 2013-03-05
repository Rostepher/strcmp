require 'ffi'

module StrCmp
    class << self
        extend FFI::Library

        # Try loading in order.
        library = File.dirname(__FILE__) + "/../ext/strcmp/strcmp"
        candidates = ['.bundle', '.so', '.dylib', ''].map { |ext| library + ext }
        ffi_lib(candidates)

        def jaro(string1, string2)
            validate(string1)
            validate(string2)
            ffi_jaro(string1, string2)
        end

        def jaro_winkler(string1, string2)
            validate(string1)
            validate(string2)
            ffi_jaro_winkler(string1, string2)
        end

        private
        # attach the c functions with ffi
        attach_function :ffi_jaro, :jaro_distance, [:string, :string], :double
        attach_function :ffi_jaro_winkler, :jaro_winkler_distance, [:string, :string], :double

        # confirm that the given object is a string, if not raise type error
        def validate(object)
            unless object.kind_of?(String)
                raise TypeError, "Wrong argument type #{object.class} (expected String)"
            end
        end
    end
end