const fs = require('fs');
const createModule = require('./docs/engine.js');

createModule().then(Module => {
    const runChallenge = Module.cwrap('run_challenge', 'number', ['number']);
    
    const limit = 10000000; // Find primes up to 10 million
    
    console.log(`--- Starting Challenge: Primes up to ${limit} ---`);
    
    const start = performance.now();
    const result = runChallenge(limit);
    const end = performance.now();
    
    const duration = (end - start).toFixed(2);
    
    console.log(`Result: Found ${result} primes.`);
    console.log(`Execution Time: ${duration}ms`);
    
    // Save result for the leaderboard
    const stats = {
        last_run: new Date().toISOString(),
        time_ms: parseFloat(duration),
        count: result
    };
    fs.writeFileSync('stats.json', JSON.stringify(stats, null, 2));
});
