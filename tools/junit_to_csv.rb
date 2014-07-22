#!/usr/bin/env ruby

require 'rexml/document'

xml = File.read(ARGV[0])

doc, arrayOfHashes, hashOfArrays = REXML::Document.new(xml), [], {}
doc.elements.each('testsuites/testsuite/testcase') do |t|
  arrayOfHashes << t.attributes
end
sortedKeys = arrayOfHashes.first.keys.sort
puts sortedKeys.join(',')

arrayOfHashes.each do |h|
  row = [];
  sortedKeys.each do |k|
    row << h[k]
  end
  puts row.join(',')
end

